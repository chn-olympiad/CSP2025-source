#include<bits/stdc++.h>
using namespace std;
int a[1005],b[15][15],len,val,n,m;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m,len=n*m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i*n-n+j];
	val=a[1];
	sort(a+1,a+n*m+1);
	for(int j=1;j<=m;j++) {
		if(j&1)for(int i=1;i<=n;i++)b[i][j]=a[len--];
		else for(int i=n;i;i--)b[i][j]=a[len--];
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(b[i][j]==val)cout<<j<<' '<<i<<endl;
	return 0;
}
