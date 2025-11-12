#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	int t=n*m,max=0;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i];
		if(a[i]>=max)
		{
			max=a[i];
		}
	}
	int x=a[1];
	sort(a+1,a+t+1);
	int st=0;
	for(int i=t;i>=1;i--)
	{
		if(a[i]==x)
			st=t-i+1;
	}
	if(st%n!=0)
	{
		if((st/n)%2==1)
		{
			cout<<st/n+1<<" "<<n-st%n+1;
		}
		else
		{
			cout<<st/n+1<<" "<<st%n;
		}
	}
	else
	{
		if((st/n)%2==1)
		{
			cout<<st/n<<" "<<n;
		}
		else
		{
			cout<<st/n<<" "<<1;
		}
	}
	return 0;
}

