#include<bits/stdc++.h>
using namespace std;
const int N=109;
int a[N],b[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c=n*m;
	for(int i=1;i<=c;i++)
	{
		cin>>a[i];
	}
	int man=a[1];
	sort(a+1,a+1+c,greater<int>());
	int l=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
		{
			l++;
			if(i%2)
			{
				b[j][i]=a[l];
			}
			else
			{
				b[n-j+1][i]=a[l];
			}
		}
	} 
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==man)
			{
				cout<<j<<" "<<i;
				f=1;
				break;
			}
		}
		if(f)
		{
			break;
		}
	}
	return 0;
}
