#include<bits/stdc++.h>
using namespace std;
const int S=1061109567;
int t[100000002],last=1,pre=1;
int n,m,k,a[1012][1012],c[10],v[10056],r[1050],k2,r1;
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y;
		a[x][y]=a[y][x]=z;
		r[x]++,r[y]++;
	}
	for(int i=1;i<=n;i++)
		if(r[i]>r1){
			r1=r[i];
			k2=i;
		}
	t[++last]=k;
	v[k1]=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int z;
		for(int j=1;j<=n;j++){
			cin>>z;
			a[n+i][j]=a[j][n+i]=z;
		}
	}
	while(last>pre){
		int k3=0,z=S;
		for(int i=i;i<=n;i++){
			if(t[pre]==i)
				continue;
			if(a[t[pre]][i]==S)
				continue;
			a[++last]=i;
			if(z>a[t[pre]][i]&&!v[i]){
				z=a[t[pre]][i];
				k3=i;
			}
		}
		a[++last]=k3;
		v[k3]=1;
		pre++;
	}
	return 0;
}
