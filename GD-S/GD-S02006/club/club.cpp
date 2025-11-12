#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5; 
long long n,a[N],num,sum,b[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		num=0;
		sum=a[i]/2;
		b[0]=0;
		b[1]=0;
		b[2]=0;
		for(int j=0;j<a[i];j++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			if(max(x,max(y,z))==x&&b[0]<sum)
			{
				b[0]++;
				num+=x;
			}
			else if(max(x,max(y,z))==y&&b[1]<sum)
			{
				b[1]++;
				num+=y;
			}
			else if(max(x,max(y,z))==z&&b[2]<sum)
			{
				b[2]++;
				num+=z;
			}
			else if(max(x,max(y,z))==x&&b[0]==sum)
			{
				if(max(y,z)==y)
				{
					num+=y;
				}
			}
			else if(max(x,max(y,z))==x&&b[0]==sum)
			{
				if(max(y,z)==z)
				{
					num+=z;
				}
			}
			else if(max(x,max(y,z))==y&&b[1]==sum)
			{
				if(max(x,z)==x)
				{
					num+=y;
				}
			}
			else if(max(x,max(y,z))==y&&b[1]==sum)
			{
				if(max(x,z)==z)
				{
					num+=z;
				}
			}
			else if(max(x,max(y,z))==z&&b[2]==sum)
			{
				if(max(x,y)==x)
				{
					num+=x;
				}
			}
			else if(max(x,max(y,z))==z&&b[2]==sum)
			{
				if(max(x,y)==y)
				{
					num+=y;
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
