#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
const ll N=1e6+5;
ll a[N][4];
ll id[4];
ll cnt[4];
ll scm[N];
ll typ[N];
void sol()
{
	id[1]=1,id[2]=2,id[3]=3;
	cin>>n;
	cnt[1]=cnt[2]=cnt[3]=0;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i][id[1]]>>a[i][id[2]]>>a[i][id[3]];
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) cnt[1]++,typ[i]=1;
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) cnt[2]++,typ[i]=2;
		else cnt[3]++,typ[i]=3;
	}
	if(cnt[2]>=cnt[1]&&cnt[2]>=cnt[3]) swap(id[1],id[2]);
	else if(cnt[3]>=cnt[2]&&cnt[3]>=cnt[1]) swap(id[1],id[3]);
	if(cnt[id[1]]>n/2)
	{
		ll ans=0;
		ll cur=0;
		for(ll i=1;i<=n;i++)
		{
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
			if(typ[i]==id[1])
			{
				scm[++cur]=a[i][id[1]]-max(a[i][id[2]],a[i][id[3]]);
			}
		}
		sort(scm+1,scm+cur+1);
		for(ll i=1;i<=cnt[id[1]]-n/2;i++) ans-=scm[i];
		cout<<ans<<"\n";
	}
	else
	{
		ll ans=0;
		for(ll i=1;i<=n;i++) ans+=max(a[i][1],max(a[i][2],a[i][3]));
		cout<<ans<<"\n";
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		sol();
	}
	return 0;
}
/*
1. 对拍

综合考量此代码通过了n=10/30的无特性大样例、证明过程简单明了、不易出错，通过概率较大，后面的题时间紧张，将对拍环节后移。 

2. -Wall OK
3. 时空限制 

time: 0.1689s/1s

mem: 47MB/512MB

4. 变量名 无误 
5. 数组大小 无误 
6. 高亮条件/边界 无误 
7. 取模 无 
8. 最后文件读写测试 
*/
