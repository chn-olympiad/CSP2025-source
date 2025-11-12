#include<bits/stdc++.h>
using namespace std;
int t;
int a,b,c;
int main()
{
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	cin>>t;
	while(t--)
	{
		int n,x=0;
		cin>>n;
		while(n--)
		{
		cin>>a>>b>>c;
		x+=max(a,max(b,c));
		}
		cout<<x<<endl;
	}
	return 0;
}
