#include<bits/stdc++.h>
using namespace std;
long long t,n,ans=0;
int a[100010][4];
void dfs(int x,int x1,int x2,int x3,long long sum){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	if(x1+1<=n/2)dfs(x+1,x1+1,x2,x3,sum+a[x][1]);
	if(x2+1<=n/2)dfs(x+1,x1,x2+1,x3,sum+a[x][2]);
	if(x3+1<=n/2)dfs(x+1,x1,x2,x3+1,sum+a[x][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){
		ans=0;n=0;
		cin>>n;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>a[i][j];
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		t--;
	}
}
