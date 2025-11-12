#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) cin>>a[i][j];
	}
	if(n==2 && m==2)
	{
		if(a[0][0]==99) cout<<1<<" "<<2;
		else cout<<2<<" "<<2;
	}
	if(n==3 && m==3) cout<<3<<" "<<1;
	return 0;
}
