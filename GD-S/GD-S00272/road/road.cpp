#include<bits/stdc++.h>
#define int long
using namespace std;
map<int,map<int,int> > mp;
map<int,map<int,bool> > vis,road;
int kk[10005][15];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0,cnt=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%ld%ld%ld",&a,&b,&c);
		mp[a][b]=c;
		mp[b][a]=c;
		vis[a][b]=1;
		vis[b][a]=1;
	}
	for(int i=1;i<=k;i++){
		cin>>kk[0][i];
		for(int j=1;j<=n;j++){
			cin>>kk[j][i];
		}
	}
	for(int i=1;i<=n;i++){
		int minn=1e9,p=0;
		if(cnt==n-1){
			break;
		} 
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			for(int l=1;l<=k;l++){
				if(kk[i][l]+kk[j][l]+kk[0][l]<minn && road[i][j]==0){
					minn=kk[i][l]+kk[j][l]+kk[0][l];
					p=j;
				}
			}
			if(vis[i][j]==0 || road[i][j]==1) continue;
			if(mp[i][j]<minn && road[i][j]==0){
				minn=mp[i][j];
				p=j;
			}
			if(cnt==n-1){
				break;
			}
		}
		if(minn!=1e9  && p!=0){
			road[i][p]=1;
			road[p][i]=1;
			cnt++;
			ans+=minn;
		}
		
	}
	printf("%ld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
