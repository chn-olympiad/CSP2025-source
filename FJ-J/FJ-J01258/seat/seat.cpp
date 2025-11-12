#include<bits/stdc++.h>
using namespace std;
const int N=102;
bool stu[N];

int n,m,r;

int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;
			cin>>x;
			if(i==1&&j==1)r=x;
			stu[x]=1;
		}
	}
	int idx=0,rp=0;
	for(int i=N;i>0;i--)
	{
		if(stu[i]==1)
		{
			idx++;
			if(i==r)rp=idx;
		}
	}
	
	int h=0, l=0;
	//²»±»Õû³ý 
	if(rp/n*n<rp)
	{
		l=rp/n+1;
		
	}
	else l=rp/n;
	if(l%2==0)
	{
		int mo=0;
		if(rp%n==0)mo=n;
		else mo=rp%n;
		h=n+1-mo;
	}
	if(l%2==1)
	{
		int mo=0;
		if(rp%n==0)mo=n;
		else mo=rp%n;
		h=mo;
	
	}
	cout<<l<<" "<<h;
	return 0;
}
