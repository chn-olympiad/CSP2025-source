#include<bits/stdc++.h>
using namespace std;
int n,m,group,num=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>group;
	for(int i=1;i<=n*m-1;i++)
    {
    	int f;
    	cin>>f;
    	if(f>group)
    	    num++;
	}
	if(num%n==0 )
	{
		if((num/n)%2==1)cout<<num/n<<" "<<n;
		if((num/n)%2==0)cout<<num/n<<" "<<1;
	}
	return 0;
}
