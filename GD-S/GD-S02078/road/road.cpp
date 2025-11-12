#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct dl{
	int v,u,z;
};
int b[15][10010];
dl a[10010];
int j=0;
bool cmp(dl x,dl y){
	return x.z<y.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	bool cz[m+5];
	memset(cz,0,sizeof(cz));
	for(int i=1;i<=n;i++){
		cin>>a[i].v>>a[i].u>>a[i].z;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	int i=1;
	int j=0;
	while(j<=m){
		if(!cz[a[i].v]||!cz[a[i].u]){
			ans+=a[i].z;
			if(cz[a[i].v]==0&&cz[a[i].u]==0) j+=2;
			else j+=1;
			cz[a[i].v]=1;
			cz[a[i].u]=1;
		}
		i++;
	}
	cout<<ans<<endl;
	return 0;
} 
