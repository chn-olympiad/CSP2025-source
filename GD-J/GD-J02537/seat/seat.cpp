#include <iostream>
#include <algorithm>
using namespace std;
int Line[120],minghhhh;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>minghhhh;
	Line[n*m]=minghhhh;
	for(int i = 1; i < n*m; i++)
		cin>>Line[i];
	sort(Line+1,Line+n*m+1,cmp);
	int r=1,l=n*m,ans;
	while(r<=l)
	{
		int mid=(r+l)/2;
		if(Line[mid]==minghhhh)
		{
			ans=mid;
			r=l+1;
		}
		else if(Line[mid]<minghhhh)
			l=mid-1;
		else
			r=mid+1;
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
			if((i-1)*n+j==ans)
				cout<<i<<' '<<j;
		i++;
		if(i<=m)
			for(int j=n; j >= 1; j--)
				if((i-1)*n+n-j+1==ans)
					cout<<i<<' '<<j;	
	}
	return 0; 
 } 
