#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int T;
int n,ans;
int a[MAXN][10];
void dfs(int p,int sum,int c1,int c2,int c3){
	if(p>n){
		ans=max(ans,sum);
		return;
	}
	if(c1+1<=n/2)
		dfs(p+1,sum+a[p][1],c1+1,c2,c3);
	if(c2+1<=n/2)
		dfs(p+1,sum+a[p][2],c1,c2+1,c3);
	if(c3+1<=n/2)
		dfs(p+1,sum+a[p][3],c1,c2,c3+1);
}
int temp[MAXN];
int dp[2][3][205][205];
int main(){
	frepen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		bool flag=true;
		for(int i=1;i<=n;i++)
			if(a[i][2]!=0) flag=false;
		if(flag){
			int ans=0;
			for(int i=1;i<=n;i++) temp[i]=a[i][1];
			sort(temp+1,temp+1+n);
			for(int i=n;i>n/2;i--) ans+=temp[i];
			cout<<ans<<endl;
			return 0;
		}
		dfs(1,0,0,0,0);
		int ans=0;
	}
	return 0;
}
/*
1 1 3
2 3 4
3 2 3
*/
