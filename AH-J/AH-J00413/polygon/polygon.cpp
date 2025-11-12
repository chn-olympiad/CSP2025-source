#include<bits/stdc++.h>

using namespace std;

int n,a[5005],used[5005];
long long ans = 0;
vector<int> v;

void dfs(int sum,int edge){
	ans = 0;
	if(int(v.size()) == edge && v[edge - 1] * 2 < sum) {
		++ans;
		return;
	}
	for(int i = 0;sum - i * (edge - int(v.size())) >= 0;++i) {
		if(used[i] != 1){
			v.push_back(a[i]);
			used[i] = 1;
			sum += a[i];
			dfs(sum,edge);
			used[i] = 0;
			v.pop_back();
			sum -= a[i];
		}
	}
}

bool CHECK(long long mid){
	long long cnt = 0;
	for(int i = 3;i <= n;++i){
		dfs(0,i);
		if(ans > 0) cnt += ans;
		if(cnt >= mid) return true;
	}
	return false;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i = 0;i < n;++i){
		scanf("%d",&a[i]);
	}
	
	sort(a,a + n);
	
	long long L = 0, R = (n - 2) * (n - 1) / 2, MID;
	while(L + 1 < R){
		MID = (L + R) / 2;
		if(CHECK(MID)) L = MID;
		else R = MID;
	}
	printf("%d",int(R % 998244353));
	return 0;
}
