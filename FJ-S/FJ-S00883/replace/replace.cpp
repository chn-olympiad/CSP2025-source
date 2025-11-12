#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q,bt[200005];
string a[200005],b[200005];
int main(){
	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for (ll i=1;i<=n;i++)
	{
		std::cin>>a[i]>>b[i];
		for (ll j=0;j<a[i].length();j++)
			if (a[i]!=b[i])
			{
				bt[i]=i;
				break;
			}
	}
	while (q--)
	{
		ll ans=0;
		string ta,tb;
		std::cin>>ta>>tb;
//		ll head=0,tail=0;
//		for (ll i=0;i<ta.length();i++)
//			if (ta[i]!=tb[i])
//			{
//				if (!head)
//					head=tail=i;
//				else
//					tail=i;
//			}
//		for (ll i=1;i<=n;i++)
//		{
//			ll flag=0;
//			if (a[i].length()<tail-head+1)
//				continue;
//			for (ll j=head-a[i].length()+bt[i]+1,k=0;j<=tail || k<a[i].length();j++,k++)
//			{
//				if (tail>=ta.length())
//				{
//					flag++;
//					break;
//				}
//				if (a[i][k]!=ta[j+k] || b[i][k]!=tb[j+k])
//				{
//					flag++;
//					break;
//				}
//			}
//			if (!flag)
//				ans++;
//		}
		printf("%lld\n",ans);
	}
	return 0;
	}

