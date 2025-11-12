#include<bits/stdc++.h>
using namespace std;
int a[200],f[20][20],b[200];
int main()
{
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,k=0;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)
	{
	     cin>>a[i];
	}
	t=a[1];
	
	if(n==1&&m==1)
	{
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	sort(a+1,a+n*m+1);
	for(int i = 1;i<=n*m;i++)
	{
	    b[i] = a[n*m-i+1];
	    if(b[i]==t) k=i;
	   
	}
	
	if(k==1)
	{
		cout << 1 << " "<<1<<endl;
		return 0;
	}
	
	if(n==1)
	{
		for(int i = 1;i<=n*m;i++)
		{
			if(b[i]==t)
			{
				cout<<i<<" "<<1;
				return 0;
			}
		}
	}
	if(m==1)
	{
		for(int i = 1;i<=n*m;i++)
		{
			if(b[i]==t)
			{
				cout<<1<<" "<<i;
				return 0;
			}
		}
	}
	if(n==2)
	{
		f[1][1]=1;
		
		for(int i = 1;i<=m;i++)
		{
			if(i%2==0) f[1][i] = 2*i;
			else f[1][i] =2*i-1;
			if(f[1][i] == k) cout<<i<<" "<<1;
		}
			for(int i = 1;i<=m;i++)
		{
			if(i%2==0) f[2][i] = 2*i-1;
			else f[2][i] =2*i;
			if(f[2][i] == k) cout<<i<<" "<<2;
		}
		return 0;
	}
	if(m==2)
	{
		f[1][1]=1;
		if(k<=m)
		{
			cout<< 1<<" "<<k;
			return 0;
		}
		else
		{
			cout <<2 <<" "<<2*n+1-k;
			return 0;
		}
	}
	return 0;
 } 
