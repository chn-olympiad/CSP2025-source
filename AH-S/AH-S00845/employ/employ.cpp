#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+25,M=2e6+25,P=998244353;
string s;
ll a[N],p[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n,m,i,ans=0;
	cin>>n>>m>>s;
	for(i=1;i<=n;i++)cin>>a[i],p[i]=i;
	if(n<=10){
	do{
		ll cnt=0,f=0;
		for(i=1;i<=n;i++)
			if(f>=a[p[i]])f++;
			else if(s[i-1]=='0')f++;
			else cnt++;
		if(cnt>=m)ans++,ans%=P;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<'\n';
	return 0;
	}
	bool flag=1;
	for(i=0;i<n;i++)
		if(s[i]=='0')flag=0;
	if(flag){
		ll w=n;
		for(i=1;i<=n;i++)
			if(a[i]==0)w--;
		ll ans=1;
		for(i=1;i<=w;i++)ans=ans*i%P;
		cout<<ans;
		return 0;
	}
}
