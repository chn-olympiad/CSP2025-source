#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
const int base1=1511,base2=1361,mod1=998244353,mod2=1e9+7;
int n,q,l[N];
ll mi1[N],mi2[N];
ll hs1[N],hs2[N],h1[N],h2[N],w1[N],w2[N];
map<pair<int,int>,int> mp;
int Q(char x,char y)
{
	return 30*(y-'a')+x-'a';
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	mi1[0]=mi2[0]=1;
	for(int i=1;i<N;i++){
		mi1[i]=mi1[i-1]*base1%mod1;
		mi2[i]=mi2[i-1]*base2%mod2;
	}
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		l[i]=s.size();
		for(int j=1;j<=s.size();j++){
			hs1[j]=(hs1[j-1]+Q(s[j-1],t[j-1])*mi1[j-1])%mod1;
			hs2[j]=(hs2[j-1]+Q(s[j-1],t[j-1])*mi2[j-1])%mod2;
		}
		w1[i]=hs1[l[i]];
		w2[i]=hs2[l[i]];
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<"0\n";
			continue;
		}
		for(int j=1;j<=s.size();j++){
			h1[j]=(h1[j-1]+Q(s[j-1],t[j-1])*mi1[j-1])%mod1;
			h2[j]=(h2[j-1]+Q(s[j-1],t[j-1])*mi2[j-1])%mod2;
		}
		int p;
		mp.clear();
		for(int i=s.size();i>=1;i--){
			p=i;
			mp[make_pair(h1[i],h2[i])]++;
			if(s[i-1]!=t[i-1]) break;
		}
		ll re=0;
		for(int i=1;i<=s.size();i++){
			for(int j=1;j<=n;j++){
				ll tmp1=(w1[j]*mi1[i-1]+h1[i-1])%mod1;
				ll tmp2=(w2[j]*mi2[i-1]+h2[i-1])%mod2;
				re+=mp[make_pair(tmp1,tmp2)];
			}
			if(s[i-1]!=t[i-1]) break;
		}
		cout<<re<<'\n';
	}
	return 0;
}
