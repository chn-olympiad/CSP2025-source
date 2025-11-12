#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[110],t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==t)
		{
			t=n*m-i+1;
			break;
		}
	}
	if(t%n==0)
    {
    	if((t/n)%2==1)
    	{
    		cout<<t/n<<" "<<n;
		}
		else
		{
			cout<<t/n<<" "<<1; 
		}
    	return 0;
    }
	if((t/n+1)%2==1)
	{
		cout<<t/n+1<<" "<<t%n;
	}
	else
	{
		cout<<t/n+1<<" "<<n-t%n+1;
	}
	return 0;
} 
