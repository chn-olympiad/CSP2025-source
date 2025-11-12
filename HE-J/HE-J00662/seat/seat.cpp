#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long c,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
	    cin>>s[i];
	}
	sort(s+1,s+n+1);
	for(long long i=1;i<=n;i++)
	{
		for(long long i=1;i<=m;i++)
		{
			if(s[i]>=s[1]&&s[i]<=s[10])			
			{
				c=1;
				l=i;
				break;
			}
			else if(s[i]>=s[11]&&s[i]<=s[20])
			{ 
			    c=2;
			    l=20-i+1;
			    break;
			}
			else if(s[i]>=s[21]&&s[i]<=s[30])
			{
				c=3;
				l=i-20;
				break;
			}
			else if(s[i]>=s[31]&&s[i]<=s[40])
			{
				c=4;
				l=40-i+1;
				break;
			}
			else if(s[i]>=s[41]&&s[i]<=s[50])
			{
				c=5;
				l=i-40;
				break;
			}
			else if(s[i]>=s[51]&&s[i]<=s[60])
			{
				c=6;
				l=60-i+1;
				break;
			}
			else if(s[i]>=s[61]&&s[i]<=s[70])
			{
				c=7;
				l=i-60;
				break;
			}
			else if(s[i]>=s[71]&&s[i]<=s[80])
			{
				c=8;
				l=80-i+1;
				break;
			}
			else if(s[i]>=s[81]&&s[i]<=s[90])
			{
				c=9;
				l=i-80;
				break;
			}
			else if(s[i]>=s[91]&&s[i]<=s[100])
			{
				c=10;
				l=100-i+1;
				break;
			}
		}
	}
	cout<<c<<" "<<l;
	return 0;
}

