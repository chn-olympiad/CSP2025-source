#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],s,h;
bool b[15][15];
int fx[4]={0,-1,1,0},fy[4]={0,0,0,1};
bool cmp(long long a,long long b){
	return a>b;
}
void dfs(long long x,long long y,long long k){
	b[x][y]=1;
	if(k==h){
		cout<<y<<' '<<x;
		exit(0);
	}
	long long tx,ty;
	for(int i=1;i<=3;i++){
		tx=fx[i]+x;
		ty=fy[i]+y;
		if(tx>0&&ty>0&&tx<=n&&ty<=m&&b[tx][ty]!=1){
			dfs(tx,ty,k+1);
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)s=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++){
		if(a[i]==s){
			h=i;
			break;
		}
	}
	dfs(1,1,1);
	return 0;
}
