#include<bits/stdc++.h>
using namespace std;
int a[150];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++)
	{
		cin>>a[i];
	}
	int temp=a[1];
	sort(a+1,a+n*m+1);
	for(int i=(n*m);i>=1;i--)
	{
		if(a[i]==temp)
		{
			if(n==1)
			{
				cout<<1<<" "<<i<<endl;
			}
			else if(n<1)
			{
				cout<<i<<" "<<1;
			}
		}
	}
	
	return 0;
} 