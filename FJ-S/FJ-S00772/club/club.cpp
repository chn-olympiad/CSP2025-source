#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][4],ans=0;
void dfs(int q,int x,int cnt,int c1,int c2,int c3){
	if(q>n){
		if(ans<cnt) ans=cnt;
		return ;
	}
	if(x==1){
		if(c1+1>n/2) return ;
		dfs(q+1,1,cnt+a[q][x],c1+1,c2,c3);
	    dfs(q+1,2,cnt+a[q][x],c1+1,c2,c3);
	    dfs(q+1,3,cnt+a[q][x],c1+1,c2,c3);
	}
	else if(x==2){
		if(c2+1>n/2) return ;
		dfs(q+1,1,cnt+a[q][x],c1,c2+1,c3);
	    dfs(q+1,2,cnt+a[q][x],c1,c2+1,c3);
	    dfs(q+1,3,cnt+a[q][x],c1,c2+1,c3);
	}
	else if(x==3){
		if(c3+1>n/2) return ;
		dfs(q+1,1,cnt+a[q][x],c1,c2,c3+1);
	    dfs(q+1,2,cnt+a[q][x],c1,c2,c3+1);
	    dfs(q+1,3,cnt+a[q][x],c1,c2,c3+1);
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=3;j++)
		        cin>>a[i][j];
		dfs(1,1,0,0,0,0);
		dfs(1,2,0,0,0,0);
		dfs(1,3,0,0,0,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
