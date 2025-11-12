#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,k,ans;
long long u[N],v[N],w[N],c[11],a[11][10001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	for(int i=1;i<n;i++){
		long long minn=1000000001;
		int xx=0,yy=0;
		for(int j=i+1;j<=n;j++){
			for(int g=1;g<=m;g++){
				if(i==u[g]&&j==v[g]&&w[g]<minn){
					minn=min(minn,w[g]);
					xx=0;
					yy=g;
				}
				else if(j==u[g]&&i==v[g]&&w[g]<minn){
					minn=min(minn,w[g]);
					xx=0;
					yy=g;
				}
			}
			for(int g=1;g<=k;g++){
				if(a[g][i]+a[g][j]+c[g]<=minn){
					minn=a[g][i]+a[g][j]+c[g];
					xx=1;
					yy=g;
				}
			}
		}
		if(xx==1)c[yy]=0;
		else{
			u[yy]=0;
			v[yy]=0;
			w[yy]=0;
		}
		ans+=minn;
	}
	cout<<ans<<endl;
	return 0;
}

