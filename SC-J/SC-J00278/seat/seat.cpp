#include<bits/stdc++.h>
using namespace std;
int x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout) 
	int n,m;
	cin>>n>>m;
	int a[n][m],al=n*m,s[al];
	for(int i=0;i<al;i++)
	{
		cin>>s[i];
	}
	int a1=s[0],k=al-1;
	bool r=true;
	sort(s,s+al);
	for(int i=0;i<n;i++)
	{
		if((i+1)%2==1)
		{
			for(int j=0;j<m;j++)
			{
				a[i][j]=s[k];
				k--;
				if(a[i][j]==a1)
				{
					r=false,x=i,y=j;
					break;
				}
			}
		}
		else
		{
			for(int j=m-1;j>=0;j--)
			{
				a[i][j]=s[k];
				k--;
				if(a[i][j]==a1)
				{
					r=false,x=i,y=j;
					break;
				}
			}
		}
		if(!r)break;
	}
	cout<<x+1<<' '<<y+1;	
	return 0;
}
 