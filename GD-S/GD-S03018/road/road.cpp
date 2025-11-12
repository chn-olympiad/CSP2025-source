#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int u[10010],v[10010],w[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	int c[k],a[k][n];
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++) cin>>a[i][j];
	}
	for(int i=0;i<m;i++){
		int uu=u[i],vv=v[i],p=0;
		for(int j=0;j<k;j++){
			for(int z=0;z<n;z++){
				if((uu=j && vv==z)||(uu==z && vv==j)){
					p=1;
					break;
				}
			}
			if(p==1) break;
		}
		if(!p) ans+=w[i];
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
