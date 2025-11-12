#include<bits/stdc++.h>
#define ll long long
ll n,m,k,o1,o2,o3,a[10005][10005],b[10005],ans,c[12],f[10005][10005],minn=1e18+5,p[10005],l,r,ok[12];
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(ll i=1;i<=10000;i++) p[i]=1e18+5;
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>o1>>o2>>o3;
		a[o1][o2]=a[o2][o1]=o3;
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>b[j];
		}
		for(ll j=1;j<=n;j++){
			for(ll w=j+1;w<=n;w++){
				if(a[j][w]>=b[j]+b[w]+c[i]||a[j][w]==0){
					a[j][w]=a[w][j]=b[j]+b[w];
					f[j][w]=f[w][j]=i;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<f[i][j]<<" ";
		}
		cout<<"\n";
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(p[n-1]>a[i][j]&&a[i][j]!=0){
				p[n-1]=a[i][j];
				sort(p+1,p+n);
				l=i,r=j;
				ok[f[l][r]]++;
			}
		}
	}
	for(ll i=1;i<=n-1;i++) ans+=p[i];
	for(int i=1;i<=k;i++){
		if(ok[i]) ans+=c[i];
	}
	cout<<ans;
	return 0;
}
