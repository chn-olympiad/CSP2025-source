#include<bits/stdc++.h>
using namespace std;
int n,m,R,lie=1;
int c[110],xia[110];
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;	
for(int i=1;i<=n*m;i++)
	{
	cin>>c[i];
	xia[i]=i;	
	}
for(int i=1;i<n*m;i++)
	{
	for(int j=i+1;j<=n*m;j++)
		{
		if(c[j]>c[i])
			{
			swap(c[j],c[i]);
			swap(xia[j],xia[i]);	
			}	
		}	
	}
for(int i=1;i<=n*m;i+=n*2)
	{
	bool flag=false;	
	for(int j=i;j<i+n*2;j++)
		{
		if(xia[j]==1)
			{
			flag=true;
			R=j-i+1;
			break;	
			}	
		}
	if(flag==true)
		break;
	lie+=2;		
	}
if(R<=n)
	{
	cout<<lie<<" "<<R;
	return 0;	
	}		
else
	{	
	cout<<lie+1<<" "<<2*n+1-R;
	return 0;
	}	
} 
