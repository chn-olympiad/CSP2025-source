#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,t,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a;
		if(n==m==1)
		{
			c=1;
			r=1;
			cout<<c<<" "<<r;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
