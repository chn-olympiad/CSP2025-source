#include <bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000001],b[1000001],c[100001],e[11],x[11][11],v[1000001],s=0,o,p=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k; 
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=k;i++){
		cin>>e[i];
		for(int j=1;j<=m;j++){
			cin>>x[i][j];
		}
	}
	while(p<m){
		long long mena=0,aj=1000001,ad,minn=1000001,mi=1000001;
		for(int i=1;i<=m;i++){
			if(v[a[i]]==1&&v[e[i]]==1)continue;
			if(minn>=c[i]){
				minn=c[i];
				mena=i;
			}
		}
		v[a[mena]]=1;
		v[e[mena]]=1;
		s+=minn;
		for(int i=1;i<=k;i++){
			if(e[i]<aj){
				aj=e[i];
				ad=i;
			}
		}
		for(int j=1;j<=m;j++){
			if(o==j)continue;
			if(mi>=x[ad][j]){
				mi=x[ad][j];
				o=j;
			}
		}
		s+=mi;
		for(int i=1;i<=n;i++){
			if(v[i]==1)p++;
		}
	}
	cout<<s;
	return 0;
}
