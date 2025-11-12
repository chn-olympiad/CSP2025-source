#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int xrid;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,1};
struct node{
	int score;
	bool xr;
	bool operator<(const node b)const{
		return score>b.score;
	}
}a[N];
int n,m;
int v[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].score;
	a[1].xr=true;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++) if(a[i].xr) xrid=i;
	v[1][1]=a[1].score;
	int j=1,i=0,dir,cnt=1,crt=1,nx=1,ny=1;
	while(j<=m){
		crt=1;
		if(j>1) crt++;
		if(j%2) dir=0;
		else dir=2;
		while(crt<=n){
			nx=i+dx[dir],ny=j;
			v[nx][ny]=a[cnt++].score;
			i=nx;
			++crt;
			if(i+dx[dir]<=0||i+dx[dir]>n) break;
		}
		j++;
		if(crt-1==n) v[nx][j]=a[cnt++].score;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(v[i][j]==a[xrid].score) cout<<j<<' '<<i;
	return 0;
}
