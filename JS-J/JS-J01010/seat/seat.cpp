#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int ans;
int b[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	ans=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;i++)
		if(i%2==1)
			for(int j=1;j<=n;j++)
				b[j][i]=a[n*m-((i-1)*n+j)+1];
		else
			for(int j=n;j>=1;j--)
				b[j][i]=a[n*m-(i*n-j+1)+1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[i][j]==ans){
				cout<<j<<' '<<i;
				return 0;
			}
}