#include<bits/stdc++.h>

using namespace std;

int n,k,a[500005],aNs = 0;

int dfs(int st){
	int ans = 0, tmpSum = a[st], tmpAns = 0;
	tmpSum = tmpSum ^ a[st];
	for(int i = st;i <= n;++i){
		if(tmpSum == k){
			tmpAns = dfs(i + 1) + 1;
			ans = max(tmpAns,ans);
		}
		tmpSum = tmpSum ^ a[i];
	}
	return ans;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d %d",&n, &k);
	for(int i = 0;i < n;++i){
		scanf("%d",&a[i]);
	}	
	for(int i = 0;i < n;++i){
		aNs = max(aNs,dfs(i));
	}
	cout << aNs << endl;
	return 0;
}
