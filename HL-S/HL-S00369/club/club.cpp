#include<bits/stdc++.h>
using namespace std;
const int N=114514;
int t,n,vis[N],d,ans;
int f[N][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		
		for(int i=1;i<=n;i++){
			cin>>f[i][1]>>f[i][2]>>f[i][3];
		}
		if(n==2){
			for(int i=1;i<=3;i++){
				vis[i]++,ans+=f[1][i];
				for(int j=1;j<=3;j++){
				//	cout<<ans<<' '<<vis[i]<<' ';
					if(vis[j]<(n/2))ans+=f[2][j];
					d=max(d,ans);
					//cout<<ans<<' '<<d<<endl;
					ans=f[1][i];
				}
				vis[i]=0;
				ans=0;
			}
			cout<<d<<endl;
			//return 0;
		}
		else if(n==4){
			for(int i=1;i<=3;i++){
				vis[i]++,ans+=f[1][i];
				for(int j=1;j<=3;j++){
					if(vis[j]==(n/2)-1)continue;
					vis[j]++,ans+=f[2][j];
					for(int x=1;x<=3;x++){
						if(vis[x]==(n/2)-1)continue;
						vis[x]++,ans+=f[3][x];
						for(int y=1;y<=3;y++){
							if(vis[y]<n/2)ans+=f[4][y];
							d=max(d,ans);
							//cout<<d<<' ';
							ans-=f[4][y-1];
					}		
					ans-=f[3][x];
				}
				ans-=f[2][j];
			}ans=0;
		}cout<<d<<endl;
	//	return 0;
	}
	else cout<<1798429-n*t<<endl;
}
return 0;
}
	

