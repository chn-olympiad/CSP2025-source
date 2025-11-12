#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[105],f[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int z=n*m;
	for(int i=1; i<=z; i++)
		cin>>a[i];
	int R=a[1],k;
	sort(a+1,a+z+1,cmp);
	for(int i=1; i<=z; i++)
		if(a[i]==R)
			k=i;
	f[1][1]=1;
	for(int j=1; j<=m; j++){
		bool p=1;
		if(j!=1 && j%2==0){
			f[1][j]=f[1][j-1]+2*n-1;
			p=0;
		}
		else f[1][j]=f[1][j-1]+1;
		for(int i=2; i<=n; i++)
			if(p==0) f[i][j]=f[i-1][j]-1;
			else f[i][j]=f[i-1][j]+1;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(f[i][j]==k){
				c=j;
				r=i;
			}
	cout<<c<<" "<<r;
	return 0;
}
