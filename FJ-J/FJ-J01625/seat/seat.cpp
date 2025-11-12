#include<bits/stdc++.h>
using namespace std;
const int N=144;
int n,m,R;
int a[N],b[12][12];
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
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				cnt++;
				b[j][i]=a[cnt]; 
			}
		}else{
			for(int j=n;j>=1;j--)
			{
				cnt++;
				b[j][i]=a[cnt];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==R)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
