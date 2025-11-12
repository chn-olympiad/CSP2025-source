#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int b[15][15],a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==1&&m==1) cout<<n<<" "<<m;
	else
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				cin>>b[i][j];
			}
		} 
		b[0][0]=1;
		for(int i=1; i<=n*m; i++)
		{
			cin>>a[i];
			int sum=a[1];
			sort(a+1,a+n*m+1);
			int num=max(a[i],a[i+1]);
			cout<<num<<" "<<num+1;
		}
	}
	return 0;
}

