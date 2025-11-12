#include<bits/stdc++.h>
using namespace std;
long long a[10001];
long long b[10001];
long long c[10001];
long long d[10001];
long long e[10001];
long long f[10001];
long long g[10001];
long long l[10001];
long long h[10001];
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,m,k;
long long s=1000,x=1000;
cin>>n>>m>>k;
int y[1001]={0};
for(int i=1;i<=m;i++){
cin>>a[i]>>b[i]>>c[i];
}
for(int i=1;i<m;i++){
s=min(s,c[i]+c[i+1]);
}
for(int i=1;i<=k;i++){
	cin>>d[i]>>f[i]>>g[i]>>h[i]>>l[i];
}
for(int i=1;i<=k;i++){
x=min(x,d[i]+f[i]+h[i]);
}
for(int i=1;i<=m;i++){
	y[i]=i;
	for(int j=1;j<=k;j++){
		if(y[i]!=i){
			if(f[i]==i){
				x=min(x,d[i]+f[i]+h[i]);
				}
			}
		}
	}
	cout<<x+s;
return 0;
}
