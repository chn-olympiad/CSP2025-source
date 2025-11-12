#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s,num=1;
	cin>>s;
	for(int i=1;i<=n*m-1;i++)
	{
		int x;
		cin>>x;
		if(x>s)num++;
	}
	int c,r;
	c=(num+n-1)/n;
	if(c%2==1)r=(num-1)%n+1;
	else r=n+1-((num-1)%n+1);
	cout<<c<<" "<<r;
	return 0;
 } 
