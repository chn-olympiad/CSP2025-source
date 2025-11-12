#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int t=0;
	int n0=0,m0=0,sign1=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--)
	{
		if(sign1==a[i])
		{
			cout<<m0+1<<" "<<n0+1<<endl;
			break;
		}
		
		if(t==0&&n0==n-1)
		{
			t++;
		}
		else if(t==1)
		{
			if(n0==n-1)
			{
				t++;
			}
			else
			{
				t=0;
			}
		}
		else if(t==2&&n0==0)
		{
			t=1;
		}//cout<<t<<" ";//×ªÏò 
		
		if(t==0)
		{
			n0++;
		}
		if(t==1)
		{
			m0++;
		}
		if(t==2)
		{
			n0--;
		}//ÒÆ¶¯ 
	}
	
}
