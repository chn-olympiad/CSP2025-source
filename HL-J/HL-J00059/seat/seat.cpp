#include<bits/stdc++.h>
using namespace std;

int n,m,grade,num=1;
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>grade;
	for(int i=1;i<=n*m-1;i++)
	{
		int x;
		cin>>x;
		if(x>grade)
			num++;
	}
	if(num%n==0)
	{
		
		if((num/n)%2==1)cout<<num/n<<" "<<n;
		if((num/n)%2==0)cout<<num/n<<" "<<1;
	}
	else
	{
		if((num/n)%2==1)cout<<num/n+1<<" "<<n-num%n+1;
		if((num/n)%2==0)cout<<num/n+1<<" "<<num%n;
	}
	return 0;
}
