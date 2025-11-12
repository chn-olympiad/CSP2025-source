#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=N/2;
int t,n,ans,nn;
int myd[N][4];
void dfs(int a,int x,int y,int z,int path,int anss){
	anss+=myd[a][path];
	if(a==n){
		ans=max(ans,anss);
		return;
	}
	if(x==nn){
		dfs(a+1,x,y+1,z,2,anss);
		dfs(a+1,x,y,z+1,3,anss);
		return;
	}
	if(y==nn){
		dfs(a+1,x+1,y,z,1,anss);
		dfs(a+1,x,y,z+1,3,anss);
		return;
	}
	if(z==nn){
		dfs(a+1,x+1,y,z,1,anss);
		dfs(a+1,x,y+1,z,2,anss);
		return;
	}
	dfs(a+1,x+1,y,z,1,anss);
	dfs(a+1,x,y+1,z,2,anss);
	dfs(a+1,x,y,z+1,3,anss);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(myd,0,sizeof(myd));
		cin>>n;
		nn=n/2;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>myd[i][1]>>myd[i][2]>>myd[i][3];
		}
		if(n<=30){
			dfs(1,1,0,0,1,0);
			dfs(1,0,1,0,2,0);
			dfs(1,0,0,1,3,0);
			cout<<ans<<endl;
			continue;
		}
		if(myd[1][2]==0&&myd[1][3]==0&&myd[2][2]==0&&myd[2][3]==0&&myd[3][2]==0&&myd[3][3]==0){
			int mm[N];
			for(int i=1;i<=n;i++){
				mm[i]=myd[i][1];
			}
			sort(mm+1,mm+n+1);
			for(int i=0;i<nn;i++){
				ans+=mm[n-i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(myd[1][3]==0&&myd[2][3]==0&&myd[3][3]==0&&myd[4][3]==0){
			int mm[N];
			for(int i=1;i<=n;i++){
				ans+=myd[i][2];
				mm[i]=myd[i][1]-myd[i][2];
			}
			sort(mm+1,mm+1+n);
			for(int i=0;i<nn;i++){
				ans+=mm[n-i];
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			ans+=myd[i][1];
		}
		cout<<ans<<endl;
	}
	return 0;
}
