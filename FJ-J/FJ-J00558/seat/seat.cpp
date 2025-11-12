#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500];
long long k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++)
	{
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+x+1);
	int x2=x/2;
	for(int i=1;i<=x2;i++)
	{
		swap(a[i],a[x-i+1]);
	}
	int position=0;
	for(int i=1;i<=x;i++)
	{
		if(a[i]==k)
		{
			position=i;
			break;
		}
	}
	int c=position/n;
	int r=position%n;
	if(r==0)
	{
		if(c%2==1)
		{
			cout<<c<<" "<<n;
		}else{
			cout<<c<<" "<<"1";
		}
	}else{
		c+=1;
		if(c%2==1)
		{
			cout<<c<<" "<<r;
		}else{
			cout<<c<<" "<<n-r+1;
		}
	}
}


