#include<bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010],c[1000010],vis[1000010][1000010],as[1000010][1000010];
int cy[100010];
int m,n,ans,k;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=m;j++){
			if(((a[i] == a[j]&&b[i] == b[j]&&i!=j)||(a[i]==b[j]&&b[i]==a[j]&&i!=j))&&vis[a[i]][b[i]]!=1&&vis[b[i]][a[i]]!=1){
				ans+=min(c[i],c[j]);
				vis[a[i]][b[i]] = 1;
				vis[b[i]][a[i]] = 1;
				as[a[i]][b[i]] = min(c[i],c[j]);
				as[b[i]][a[i]] = min(c[i],c[j]);
			}
			else{
				if(vis[a[i]][b[i]]!=1&&vis[b[i]][a[i]]!=1&&as[a[i]][b[i]]<c[i]){
					ans-=as[a[i]][b[i]];
					as[a[i]][b[i]] = c[i];
					ans+=c[i];
					vis[a[i]][b[i]] = 1;
					vis[b[i]][a[i]] = 1;
				}if(vis[a[j]][b[j]]!=1&&vis[b[j]][a[j]]!=1){
					ans-=as[a[j]][b[j]];
					as[a[j]][b[j]] = c[j];
					ans+=c[j];
					vis[a[j]][b[j]] = 1;
					vis[b[j]][a[j]] = 1;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

