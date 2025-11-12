#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t,n;
int a[N][3];
int ans;
pair<int,int> s[N];

bool cmp(int x,int y){
	return x > y;
}

bool cmpp1(pair<int,int> p1,pair<int,int> p2){
	return p1.first > p2.first;
}

bool cmpp2(pair<int,int> p1,pair<int,int> p2){
	return p1.second > p2.second;
}

void fun(){
	vector<int> v;
	v.clear();
	for(int i = 1;i <= n;i++) v.push_back(a[i][1]);
	sort(v.begin(),v.end(),cmp);

	for(int i = 1;i <= n / 2;i++) ans += v[i - 1];
	return ;
}

void fun2(){
	vector<int> v1,v2;
	v1.clear(),v2.clear();
	for(int i = 1;i <= n;i++){
		s[i].first = a[i][1];
		s[i].second = a[i][2];
	}
	sort(s + 1,s + n + 1,cmpp1);
	
	for(int i = 1;i <= n / 2;i++) ans += s[i].first;
	for(int i = n / 2 + 1;i <= n;i++) ans += s[i].second;
	
	int res = 0;
	sort(s + 1,s + n + 1,cmpp2);
	for(int i = 1;i <= n / 2;i++) res += s[i].second;
	for(int i = n / 2 + 1;i <= n;i++) res += s[i].first;
	
	ans = max(res,ans);
}

void dfs(int id,int cnt1,int cnt2,int cnt3,int res){
	if(cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2) return ;
	if(id > n){
		// cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
		ans = max(ans,res);
		return ;
	}
	
	dfs(id + 1,cnt1 + 1,cnt2,cnt3,res + a[id][1]);
	dfs(id + 1,cnt1,cnt2 + 1,cnt3,res + a[id][2]);
	dfs(id + 1,cnt1,cnt2,cnt3 + 1,res + a[id][3]);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans = 0;
		bool f_a = true,f_b = true;
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				scanf("%d",&a[i][j]);
				if(j != 1 && a[i][j]) f_a = false;
				if(j == 3 && a[i][j]) f_b = false;
			}
		}
		if(f_a) fun();
		else if(f_b) fun2();
		else dfs(1,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}

