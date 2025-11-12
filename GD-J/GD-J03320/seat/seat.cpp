#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,rr=0,a[100086];
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
		if(i==0)r=a[i];
	}
	sort(a,a+n*m);
	for(int i=n*m-1,j=1;i>-1;i--,j++)
	{
		if(a[i]==r)rr=j;
	}
	int bol=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(bol==0)
		{
			bol=1;
			for(int j=1;j<=m;j++)
			{
				ans++;
				if(ans==rr)
				{
					cout<<i<<" "<<j;
					bol=3;
					break;
				}
			}
		}
		else if(bol==1)
		{
			bol=0;
			for(int j=m;j>0;j--)
			{
				ans++;
				if(ans==rr)
				{
					cout<<i<<" "<<j;
					bol=3;
					break;
				}
			}
		}
		if(bol==3)
		{
			break;
		}
	}
	return 0;
} 
