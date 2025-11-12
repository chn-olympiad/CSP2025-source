#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
struct N{
	int v,id;
}a[110];
bool cmp(N a,N b){
	return a.v>b.v;
}
int f[4][2]={{0,1},{1,0},{0,-1},{1,0}};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[(i-1)*m+j].v;
			a[(i-1)*m+j].id=(i-1)*m+j;
		}
	}
	sort(a+1,a+1+n*m,cmp);
	int p=1,x=1,y=1,k=0;
	while(a[p].id!=1){
		if(y+f[k][1]>n||y+f[k][1]<1){
			k=(k+1)%4;
		}
		x+=f[k][0];
		y+=f[k][1];
		if(k&1)k=(k+1)%4;
		p++;
	}
	cout<<x<<" "<<y<<'\n';
	return 0;
}

