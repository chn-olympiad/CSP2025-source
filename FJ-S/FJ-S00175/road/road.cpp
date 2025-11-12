#include<bits/stdc++.h>
using namespace std;
int n,m,k; //城 道路 乡镇 
bool pre[10010][10010],v[10010][10010],v2[10010][10010],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int a=0,b=0,c=0;
		cin>>a>>b>>c;
		pre[a][b]=true;
		pre[b][a]=true;
		v[a][b]=c;
		v[b][a]=c;
	}
	for (int i=1;i<=k;i++){
		cin>>v2[i][0];
		for (int j=1;j<=n;j++){
			cin>>v2[i][j]; //价格为vi的乡镇到j城价格
			if (v2[i][0]==0){
				ans+=v2[i][j];
			}	
			if (j==n&&ans!=0){
				cout<<ans;
				return 0;
			}	
	    }
	}
	ans=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (v[i][j]){
				ans+=v[i][j];
			}
		}
	}
	cout<<ans/2;
	return 0;
}
