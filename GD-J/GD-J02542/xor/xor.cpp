#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010],l,ans,o=1;
void f()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=l;j<i;i++)
		{
			if((s[i]^a[l])==m)
		    {
			    ans=ans+2-o;l=i+o-1;
			    break;
		    }
		} 
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)s[i]=s[i-1]^a[i];
	f();
	return 0;
}
