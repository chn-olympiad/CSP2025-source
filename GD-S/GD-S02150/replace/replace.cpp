#include<bits/stdc++.h>
using namespace std;
#define ll int
#define LL long long
ll read(){
	ll rs=0,w=1;
	char c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')w=-1,c=getchar();
	while('0'<=c&&c<='9'){
		rs=rs*10+c-'0';c=getchar();
	}
	return rs*w;
}
const ll N=1e5+10,M=1e6+10;
string st[N],sn[N];
struct Hash{
	const LL mod=1e9+7,bass=114517;
	vector<LL>hsz,bs;
	void insert(string s){
		hsz.clear();bs.clear();
		hsz.push_back(0);bs.push_back(1);
		hsz[0]=0;bs[0]=1;
		for(ll i=1;i<s.size();i++){
			hsz.push_back((hsz[i-1]*bass+s[i])%mod);
			bs.push_back((bs[i-1]*bass)%mod);
		}
	}
	LL get(ll l,ll r){
		return ((hsz[r]-hsz[l-1]*bs[r-l+1]%mod+mod)%mod);
	}
}hsst[N],hssn[N];
ll n,q;Hash hst1,hst2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(ll i=1;i<=n;i++){
		cin>>st[i]>>sn[i];st[i]=' '+st[i];sn[i]=' '+sn[i];
		hsst[i].insert(st[i]);
		hssn[i].insert(sn[i]);
	}
//	puts("jb");
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		t1=' '+t1;t2=' '+t2;
		hst1.insert(t1),hst2.insert(t2);
		ll as=0;
		for(ll i=1;i<t1.size()&&i<t2.size();i++){
//			cout<<i<<'\n';
			for(ll j=1;j<=n;j++){
				ll lt=i,rt=st[j].size()-1+i-1,ln=i,rn=sn[j].size()-1+i-1;
				if(rt>=t1.size()||rn>=t2.size())continue;
//				cout<<lt<<' '<<rt<<' '<<ln<<' '<<rn<<'\n';
				if(hsst[j].get(1,st[j].size()-1)!=hst1.get(lt,rt)||hssn[j].get(1,sn[j].size()-1)!=hst2.get(ln,rn))continue;
				if(hst1.get(rt+1,t1.size()-1)!=hst2.get(rn+1,t2.size()-1))continue;
				as++;
			}
			if(t1[i]!=t2[i])break;
		}
		cout<<as<<'\n';
	}
}
