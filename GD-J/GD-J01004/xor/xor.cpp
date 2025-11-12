#include<bits/stdc++.h>
#define int long long
using namespace std;
const int BIG=3e6;
struct ff{
	int l,r,len;
}ans[BIG];
int n,K,k,nr,ans1,b[BIG],a[BIG],cf[BIG];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>n>>K;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=b[i-1]^a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((b[j]^b[i-1])==K)
			{
				ans[++k].l=i;
				ans[k].r=j;
				ans[k].len=j-i;
			}
	sort(ans+1,ans+1+k,[](ff x,ff y)
	{
		if(x.len!=y.len)return x.len<y.len;
		else return x.l<y.l;
	});
	for(int i=1;i<=k;i++)
	{
		int pd=0;
		for(int j=ans[i].l;j<=ans[i].r;j++)
			if(cf[j]){pd=1;break;}
		if(pd)continue; 
		for(int j=ans[i].l;j<=ans[i].r;j++)cf[j]=1;
		ans1++;
	}
	cout<<ans1;
	return 0;
}
