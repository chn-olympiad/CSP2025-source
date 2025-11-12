#include<bits/stdc++.h>
using namespace std;
int s,n,h,k,f,m[195];
int main()
{
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
cin>>n>>k;
if(n==1&&k==1)
{
	int aa;
	cin>>aa;
	cout<<aa;
	return 0;
}
for(int i=0;i<n*k;i++)
{
	cin>>m[i];
}
f=m[0];
sort(m,m+n*k);

int q=n*k-1;
int p=q;
if(m[n*k-1]==f)
{
	cout<<"1 1";
	return 0;
}
for(int i=1;i<=n;i++)
{
	h=0;

	for(int j=1;j<=k;j++)
	{
		
	
		if(m[q]==f)
		{
			 if(k==1)
{
	cout<<"1 "<<p-q+1;
	return 0;
}

 else if(n==1)
{
	cout<<p-q+1<<" 1";
	return 0;
}

		if((p-q)%(2*n)<n&&(p-q)%(2*n))
		{
			cout<<i<<" "<<j;
			return 0;
		}	
		else
		{
			cout<<i<<" "<<n-j+1;
			return 0;
			
		}
		
			
		}
		q--;
		
	}
	
}
return 0;
}
