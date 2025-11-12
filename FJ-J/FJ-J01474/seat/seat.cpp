#include<iostream>
#include<algorithm>
using namespace std;

int n,m,h=1,l=1;

struct snack
{
	int id,point;
}a[10000];

bool cmp(snack a,snack b)
{
	return a.point>b.point;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{cin>>a[i].point;a[i].id=i;}
	
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m*n;i++)
	{
	    if(a[i].id==1)
	    {
	    	cout<<l<<" "<<h;
	    	return 0;
		}
		else
		{
			if(l%2==1)
			{
				if(h<m)
				h++;
				else if(h==m)
				{
					l++;
				}
			}
			else if(l%2==0)
			{
				if(h>1)
				h--;
				else if(h==1)
				{
					l++;
				}
			}
		}
	}
	
	return 0;
 } 
