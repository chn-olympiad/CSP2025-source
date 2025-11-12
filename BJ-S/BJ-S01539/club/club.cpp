#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,i,n,s,b,c;
	cin>>t;
	while(t--)
	{
		s=0;
		cin>>n;
		for(i=1;i<=n;i++)
		  cin>>a[i]>>b>>c;
		sort(a+1,a+n+1);
		if(n%2==1)
		  b=n/2+2;
		else
		  b=n/2+1;
		for(i=n;i>=b;i--)
		  s+=a[i];
		cout<<s<<endl;
	}
}
