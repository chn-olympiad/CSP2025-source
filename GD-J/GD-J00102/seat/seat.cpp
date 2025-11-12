#include<bits/stdc++.h>
using namespace std;
int a[1001],n,m,f[101][101],l;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(int i=1; i<=l; i++) 
		cin>>a[i];
	int ans=a[1];
	sort(a+1,a+1+l);
	int cnt=l;
	for(int i=1; i<=m; i++)
		if(i%2==0)
			for(int j=n; j>=1; j--)
				f[i][j]=a[cnt--];
		else
			for(int j=1; j<=n; j++)
				f[i][j]=a[cnt--];
	for(int i=1; i<=m; i++) 
		for(int j=1; j<=n; j++) 
			if(f[i][j]==ans) {
				cout<<i<<" "<<j<<"\n";
				return 0;
			}
	return 1;
}
