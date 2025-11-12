#include<bits/stdc++.h>
using namespace std;
int n,m,s,i,n1=1,m1=1,s1,p2;
int p=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	s=n*m-1;
	if(m>10||n>10)
    {
			return 0;
    }
	int b[s];
	cin>>s1;
	while(1)
	{
		cin>>b[s];
		i++;
		//cout<<b[s];
		if(i==n*m-1)
		{
			break;
		}
	}
	for(int j;j<=n*m;j++)
	{
		
		if(m1==m&&p==1)
		{
			n1++;
			p=0;
		}
		if(m1==1&&p==0)
		{
			n1++;
			p=1;
		}
		if(s1<b[s+1]&&p==1)
		{
			m1++;
			
		}
		if(s1<b[s+1]&&p==0)
		{
			m1--;
			
		}
		b[s]++;
		if(n1==n&&p==1)
		{
			if(m1==m)
			{
				p2=1;
			}
			
		}
		
		if(n1==n&&p==0)
		{
			if(m1==1)
			{
				p2=1;
			}
			
			
				
			
			
		}
		if(p2==1)
		{
			break;
		}
		
    }
	   cout<<n1<<" "<<m1;
}
