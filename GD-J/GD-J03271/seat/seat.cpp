#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n,m,a[102];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l=n*m;
	for(int i=1;i<=l;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+l+1);
	int d=0;
	int x=0,y=0;
	for(int i=l;i>=1;i--)
	{
		d++;
		if(a[i]==r)
		{
			int de=d/n,dr=d%n;
			int dp=de;
			if(dr!=0)
			{
				de++;
			}
			else
			{
				dr+=n;
			}
			if(de%2==0)
			{
				cout<<de<<' '<<n-dr+1;
				break;
			}
			else
			{
				cout<<de<<' '<<dr;
				break;
			}
			
		}
	}
	return 0;
}
	
