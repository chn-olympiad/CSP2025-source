#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][5],ans=0,p[N];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int k1,int k2,int k3,int sum){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	int p=0;
	if(k1+1<=n/2)dfs(x+1,k1+1,k2,k3,sum+a[x][1]);
	if(k2+1<=n/2)dfs(x+1,k1,k2+1,k3,sum+a[x][2]);
	if(k3+1<=n/2)dfs(x+1,k1,k2,k3+1,sum+a[x][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int k=0,f1=0,f2=0,res=0;
		ans=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(j==1)p[++k]=a[i][j];
			if(j==2&&a[i][j]!=0)f1=1;
			if(j==3&&a[i][j]!=0)f2=1;
		}
		if(!f1&&!f2){
			sort(p+1,p+k+1,cmp);
			for(int i=1;i<=n/2;i++)res+=p[i];
			cout<<res<<endl;
		}	
		else{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
