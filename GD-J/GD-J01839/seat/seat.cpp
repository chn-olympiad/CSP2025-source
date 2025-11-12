#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105][105],r;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=1,o=1;
	for(int i=1;i<=m;i++)
	{
		
		if(k%2==1)
		{
			for(int j=1;j<=n;j++) 
			{
				b[i][j]=a[o];
				o++;
			}
		}
		else 
		{
			for(int j=n;j>=1;j--)
			{
				b[i][j]=a[o];
				o++;
			}
		}
		k++;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[i][j]==r)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
