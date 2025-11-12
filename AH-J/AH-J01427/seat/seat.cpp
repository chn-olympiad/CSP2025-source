#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,s=0;
	cin>>n>>m;
	long long a[n][m];   
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>a[0][0]) s++;
		}
	}
	cout<<s/n+1<<' ';
	if((s/n+1)%2==0) cout<<n-s%n;
	else cout<<s%n+1;
	return 0;
}
