#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=5e6+5,MOD=998244353;
int len[N],n,q;
ll a[N],b[N],f[M],sum1[N],sum2[N];
void init(){
	f[0]=1;
	for(int i=1;i<=5e6;i++)
		f[i]=f[i-1]*27%MOD;
}
int main(){
	freopen("replace3.in","r",stdin);
	freopen("replace3.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	init();
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		ll x=0,y=0;
		for(int j=0;s[j];j++) x=(x*27+s[j]-'a')%MOD;
		for(int j=0;t[j];j++) y=(y*27+t[j]-'a')%MOD;
		a[i]=x,b[i]=y,len[i]=s.size();
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		int m=s.size();
		s='#'+s,t='#'+t;
		if(s.size()!=t.size()) {
			cout<<"0\n";
			continue;
		}
		ll x=0,y=0,cnt=0;
		for(int i=1;i<=m;i++) sum1[i]=sum2[i]=0;
		for(int i=1;i<=m;i++){
			x=(x*27+s[i]-'a')%MOD;
			y=(y*27+t[i]-'a')%MOD;
			sum1[i]=x,sum2[i]=y;
		}
		for(int i=1;i<=m;i++){
			ll u=((sum1[m]-sum1[i]*f[m-i])%MOD+MOD)%MOD;
			ll v=((sum2[m]-sum2[i]*f[m-i])%MOD+MOD)%MOD;
			for(int j=1;j<=n;j++){
				if(i>=len[j]){
					ll p=((sum1[i]-sum1[i-len[j]]*f[len[j]])%MOD+MOD)%MOD;
					ll q=((sum2[i]-sum2[i-len[j]]*f[len[j]])%MOD+MOD)%MOD;
					if(p==a[j]&&q==b[j]&&u==v&&sum1[i-len[j]]==sum2[i-len[j]]) cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
