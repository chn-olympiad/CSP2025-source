#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=1,y=1,flag=0;
	cin>>n>>m;
	long long l=n*m;
	vector<int> a(l);
	for(int i=0;i<l;i++)
	{
		cin>>a[i];
	}
	int r=a[0];
	sort(a.begin(),a.end());
	vector<int> b(l);
	int k=0;
	for(int i=l-1;i>=0;i--)
	{
		b[k]=a[i];
		k++;
	}
	for(int i=0;i<l;i++)
	{
		if(b[i]==r)
		{
			cout<<x<<" "<<y;
			return 0; 
		}
		else 
		{
			if(flag==0)
			{
				if(y==n)
				{
					flag=1;
					x++;
				}
				else y++;	 
			}		
			else
			{
				if(y==1)
				{
					flag=0;
					x++;
				}
				else y--;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0; 
}
