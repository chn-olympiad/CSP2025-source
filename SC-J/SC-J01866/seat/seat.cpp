#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[20005];
int R;
int cnt=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
    	cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				cnt++;
				if(a[cnt]==R) 
				{
					cout<<i<<" "<<j;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				cnt++;
				if(a[cnt]==R) 
				{
					cout<<i<<" "<<j;
				}
			}
		}
	}
    return 0;
} 