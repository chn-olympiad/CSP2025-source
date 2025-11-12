#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,cj[1000000],a[150],tot=0,mmax=-1,sum=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		int b;
		cin>>b;
		a[b]++;
		cj[i]=b;
		if(mmax<b)
			mmax=b;
	}
	for(int i=mmax;i>=cj[0];i--)
	{
		tot++;
	}	
	if(tot<=m)
		cout<<1<<" "<<tot;
	else
	{
		while(tot>n)
		{
			tot-=n;
			sum++;
		}
		if(sum%2==0)
		{
			cout<<sum<<" "<<n-tot+1;
		}
		else
		{
			cout<<sum<<" "<<tot;
		}
	}
	return 0;
}