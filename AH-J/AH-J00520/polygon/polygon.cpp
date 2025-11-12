#include<bits/stdc++.h>
using namespace std;
int n,a[5005],mx=0,b,c;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3) {cout<<0;return 0;}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=n;i++)
		if(a[i]!=mx&&b==0)
			b=a[i];
		else if(a[i]!=mx&&c==0)
			c=a[i];
	if((b+c+mx)>(mx*2))
		cout<<1;
	else
		cout<<0;
	return 0;
}
