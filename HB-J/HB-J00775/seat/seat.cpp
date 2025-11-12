#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],xiaor,huao;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	xiaor=a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<m*n;i++){
		if(a[i]==xiaor)
		{
			huao=i+1;	
		}
	}
	if(huao%n!=0)
	{
		cout<<huao/n+1<<" ";
		if((huao/n+1)%2!=0)
		{
			cout<<huao%n;
		}
		else if((huao/n+1)%2==0)
		{
			cout<<n-huao%n+1;
		}
	}
	else if(huao%n==0)
	{
		cout<<huao/n<<" ";
		if((huao/n)%2!=0)
		{
			cout<<n;
		}
		else if((huao/n)%2==0)
		{
			cout<<1;
		}
	}
	return 0;
}
