#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m,a[N][N],g[N],x;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>g[(i-1)*n+j];
			if(i==1&&j==1)x=g[1];
		}
	sort(g+1,g+n*m+1,cmp);
	int xx,y;
	for(int i=1;i<=n;i++){
		if(i%2==0)for(int j=m;j>=1;j--)a[i][j]=g[(i-1)*n+(m-j+1)];
		else for(int j=1;j<=m;j++)a[i][j]=g[(i-1)*n+j];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]==x){
				cout<<i<<' '<<j;
				return 0;
			}
	return 0;
}
