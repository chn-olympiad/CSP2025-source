#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[105],n,m,c,r,xr,rs;
int v[15][15];
bool cmp(int w,int s){
	return w>s;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	memset(v,0,sizeof(v));
	cin>>n>>m;
	rs=n*m;
	for(int i=1;i<=rs;i++)
		cin>>a[i];
	xr=a[1];
	sort(a+1,a+1+rs,cmp);
	int cnt=0,x=1,y=1;
	v[1][1]=a[++cnt];
	while(cnt<rs){
		while(x<n&&cnt<rs) v[++x][y]=a[++cnt];
		if(y<m&&cnt<rs) v[x][++y]=a[++cnt];
		while(x>1&&cnt<rs) v[--x][y]=a[++cnt];
		if(y<m&&cnt<rs) v[x][++y]=a[++cnt];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(xr==v[i][j]){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
