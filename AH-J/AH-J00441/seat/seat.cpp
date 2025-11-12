#include<bits/stdc++.h>
using namespace std;
int c[105][105];
int a[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int o=0;

	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int p=1;
	for(int i=1;i<=n*m;i++)
		for(int j=i+1;j<=n*m;j++)
			if(a[j]>a[j-1])
			{
				if(j-1==p)p=j;
				swap(a[j],a[j-1]);
			}
	int y=1;
	for(int i=1;i<=m;i++)
		{
			if(i%2==1){for(int j=1;j<=n;j++){y++;if(y==p){cout<<n<<" "<<m;break;}
			}else for(int j=n;j>0;j--){y++;if(y==p){cout<<n<<" "<<m;break;}}
			if(y==p){break;}
			}
			
	return 0;
}
