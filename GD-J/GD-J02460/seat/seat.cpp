#include<bits/stdc++.h>
using namespace std;
const int N=20;
int a[N][N],b[N*N],len,n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>b[i];int num=b[1];
	sort(b+1,b+n*m+1,[](int x,int y){return x>y;});
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
			for(int j=1;j<=n;j++)a[i][j]=b[++len];
		else
			for(int j=n;j;j--)a[i][j]=b[++len];
	}
//	for(int i=1;i<=m;i++){for(int j=1;j<=n;j++)printf("%d ",a[i][j]);puts("");}
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)if(a[i][j]==num){cout<<i<<" "<<j<<'\n';return 0;}
	return 0;
}
/*
2 2
98 99 100 97
*/
