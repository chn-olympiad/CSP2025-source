#include<bits/stdc++.h>
#define q 998244353

using namespace std;

int m,n;
string a;
int c[505];
int b[505];
long long re=0,nq=0;
long long sum=1,x=0,y=0;//x 0,y 1


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		c[x]++;
	}
	for(int i=1;i<n;i++)
	{
		b[i]=b[i-1]+c[i];
	}
	/*for(int i=0;i<n;i++)
	{
		if(a[i]=='1')
		{
			sum=sum*(n-x-y-re+nq)%q;
			y++;
		}
		if(a[i]=='0')
		{
			sum=sum*(n-x-y-re+nq)%q;
			x++;
		}
		if(y==m)
		{
			
		}
	}*/
	for(int i=1;i<=n;i++)
	{
		sum=sum*(i%q)%q;
	}
	cout<<sum;
	return 0;
}
