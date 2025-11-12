#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,x=-1,num=0,ans=0,y[10005],q[10005];
	int u[10005],v[10005],w[10005],c[10005];
	cin>>n>>m>>k;
	int s=n;
	for(int i=1;i<=n;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=n;i++)
	if(w[i]>x) x=w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		y[i]=10005;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]<y[i]){
				y[i]=a[i][j];
				q[i]=j;
			}
		}
	}
	for(int i=1;i<=k;i++){
		int p=q[i];
		a[i][p]+=c[i];
		for(int j=1;j<=n;j++){
			
			if(c[i]<x&&a[i][j]<x){
				s++;
				u[s]=n+i;
				v[s]=j;
				w[s]=a[i][j];
			}
		}
	}
	for(int i=1;i<=s;i++){
		int r=10005,t,q;
		for(int j=1;j<=s;j++){
			if(w[j]<r&&x<n-1){
				r=w[j];
				t=j;
			}
		}
		if(num<m){
			ans+=w[t];
			num++;
			w[t]=10006;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
