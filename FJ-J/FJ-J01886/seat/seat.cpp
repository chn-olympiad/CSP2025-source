#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m;
int a[150];
bool cmp(int x,int y)
{
	return x>y; 
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i];
	int e=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			
			int r;
			r=(i-1)*n+j;
			if(a[r]==e)
			{
				if(i%2!=0)	cout<<i<<" "<<j<<endl;
				else	cout<<i<<" "<<n-j+1<<endl;
			}
	
		}
	}
	return 0;
} 
