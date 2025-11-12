#include<bits/stdc++.h>
using namespace std;

struct sc{
	int s;
	int l;
}a[105];


bool rule(sc x,sc y){
	if(x.s<y.s)
		return false;
	else
		return true;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	int j=0;
	cin>>m>>n;
	for(int i=0;i<m*n;i++)
	{
		cin>>a[i].s;
		a[i].l=i+1;
	}
	sort(a,a+m*n,rule);
	int ans=0;
	for(int i=0;i<m*n;i++)
	{
		if(a[i].l==1)
		{
			ans=i+1;
		}
	}
	if((ans/n)%2==0)
	{
		if(ans%n!=0)
		{
			cout<<ans/n+1<<" "<<ans%n;
		}
		else
		{
			cout<<ans/n<<" "<<1;
		}
	}
	else
	{
		if(ans%n!=0)
		{
			cout<<ans/n+1<<" "<<n+1-ans%n;
		}
		else
		{
			cout<<ans/n<<" "<<n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
	
}
