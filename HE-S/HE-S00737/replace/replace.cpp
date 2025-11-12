#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+3,sk=133,mod=998244353;
int n,q;
string s1,s2;
struct jjj{ll a1,a2;int z;}a[N];
ll h[N],f1[N],f2[N];
ll hhh(string s)
{
	ll res=0;
	int f=s.size();
	for(int i=1;i<f;++i) res=(res+(s[i]-'a'+1)*h[i])%mod;
	return res;
}
int k;
void bbb()
{
	for(int i=1;i<k;++i) f1[i]=(f1[i-1]+(s1[i]-'a'+1)*h[i])%mod;
	for(int i=1;i<k;++i) f2[i]=(f2[i-1]+(s2[i]-'a'+1)*h[i])%mod;
}
bool check(int i,int j)
{
	ll res2=a[i].a2*h[j-a[i].z+1]%mod;
	ll rk2=((f2[j]-f2[j-a[i].z])%mod+mod)%mod;
	return res2==rk2;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	h[0]=1;
	for(int i=1;i<=N;++i) h[i]=(h[i-1]*sk)%mod;
	for(int i=1;i<=n;++i)
	{
		cin>>s1>>s2;
		s1=' '+s1,s2=' '+s2;
		a[i].z=s1.size();
		a[i].a1=hhh(s1),a[i].a2=hhh(s2);
	}
	while(q--)
	{
		int ans=0;
		cin>>s1>>s2;k=s1.size();
		s1=' '+s1,s2=' '+s2;
		bbb();
		for(int i=1;i<=n;++i)
			for(int j=a[i].z+1;j<=k;++j)
				if(check(i,j)) ++ans;
		cout<<ans<<"\n";
	}
	return 0;
}
