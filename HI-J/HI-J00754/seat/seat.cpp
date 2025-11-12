#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105];
int b[15][15];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	int o=n*m;
	sort(a+1,a+1+o,cmp); 
	int num=1;
	int ans=1;
	for(int i=1;i<=m;i++)
	{
		if(num%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				b[j][i]=a[ans++];
			}
			num++;
		}
		else{
			for(int j=n;j>=1;j--)
			{ 
				b[j][i]=a[ans++];
			}
			num++;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==x) {
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}


