#include<bits/stdc++.h>
using namespace std;
struct cs{
	int c,cp[1005],f;
}b[15];
int n,m,k,x,y,p,sum,d;
int a[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=-1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>p;
		a[x][y]=p;
		sum+=p;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i].c;
		for(int j=1;j<=n;j++)cin>>b[i].cp[j];
	}

	for(;d<=k;d++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(b[d].cp[i]+b[d].cp[j]+b[d].c<=a[i][j]){
					if(b[d].f!=1){
						sum+=b[d].c;
						b[d].f=1;
					}
					sum-=a[i][j]-b[d].cp[i]+b[d].cp[j];
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
