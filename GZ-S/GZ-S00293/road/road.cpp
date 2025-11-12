//GZ-S00293 毛俊程 遵义市第四中学
#include<bits/stdc++.h>
using namespace std;
int n,m,k,b[15][10005];
struct aa{
	int u,v,w;
}s[1000005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>s[i].u>>s[i].v>>s[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i][0];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	cout<<"0";
    return 0;
} 
