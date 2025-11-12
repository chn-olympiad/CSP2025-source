#include<bits/stdc++.h>
using namespace std;
int n,m,score,seat,k;
int s[1001];
bool kp(int a,int b)
{	
	return a>b; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	swap(n,m); 
	for(int i=1; i<=n*m; i++)
	{
		cin>>s[i];
	}
	score=s[1];
	
	sort(s+1,s+1+n*m,kp);
	
	for(int i=1; i<=n*m; i++)
	{
		if(score==s[i])
		{
			seat=i;
			break;
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		if(i%2==1)
		{
			for(int j=1; j<=m; j++)
			{
				k+=1;
				if(k==seat)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=m; j>=1; j--)
			{
				k+=1;
				if(k==seat)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	
	return 0;
}
