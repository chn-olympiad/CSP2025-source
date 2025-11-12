#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[100001][5];
int dfs(int k,int n1,int n2,int sum){
	if(k==n+1) return sum;
	int ans=-1;
	if(n1<(n/2)) ans=max(ans,dfs(k+1,n1+1,n2,sum+a[k][1]));
	if(n2<(n/2)) ans=max(ans,dfs(k+1,n1,n2+1,sum+a[k][2]));
	if((k-n1-n2-1)<(n/2)) ans=max(ans,dfs(k+1,n1,n2,sum+a[k][3]));
	return ans;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++) cin>>a[i][j];
		cout<<dfs(1,0,0,0)<<endl;
	}
	return 0;
}/*
danminyang
danqijiasu
N2jiasousousousousousou*/
