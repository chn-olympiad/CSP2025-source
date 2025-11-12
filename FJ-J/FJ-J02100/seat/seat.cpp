#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005],f[105][105],xr;
int hs(int b,int c)
{
	return b>c;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	xr=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,hs);
	int i1=0,j1=1;
	bool ok=true;
	for(int i=1;i<=n*m;i++)
	{
		if(ok)
		{	
			if(j1%2==1)
			{
				i1++;
			}
			else {
				i1--;
			}
		}
		else{
			ok=true;
		}
		//¼Ói1 
		if(a[i]==xr)
		{
			cout<<j1<<" "<<i1;
			break;
		}
		//Êä³ö 
		if(j1%2==1)
		{
			if(i1==n)
			{
				j1++;
				ok=false;
			}
		}
		else{
			if(i1==1)
			{
			j1++;
			ok=false;
			}
		}
		//ÅÐ¶Ï»»ÐÐ 
	}
	return 0;
}



