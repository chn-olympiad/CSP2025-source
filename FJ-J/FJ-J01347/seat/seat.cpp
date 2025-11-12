#include<bits/stdc++.h>
using namespace std;
int xrzh;
int sd[1000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	int a=1;
	for(int i=1;i<=n*m;i++)
	{
		cin>>sd[i];
	 } 
	 int xr=sd[1];
	int ma=-1;
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(sd[i]>sd[j])
			{
				ma=sd[i];
				sd[i]=sd[j];
				sd[j]=ma;
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(sd[i]==xr)
		{
			xrzh=i;
		}
	}
	int ls,hs;
	if(xrzh%n==0)
	{
		hs=n;
		ls=xrzh/n;
		cout<<ls<<" "<<hs;
		return 0;
	}else if(xrzh%n!=0){
		ls=xrzh/n+1;
		if(ls%2==0){
			hs=n-xrzh%n+1;
		}
		if(ls%2!=0)
		{
			hs=xrzh%n;
		}
		cout<<ls<<" "<<hs;
		return 0;
	}
	
	return 0;
}

