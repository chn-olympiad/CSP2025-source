#include<bits/stdc++.h>
#define N 200010
#define M 5000010
using namespace std;
typedef long long ll;
const ll base1=133,base2=157;
const ll mod1=998244353,mod2=1000000007;
ll b1[M],b2[M],len[N];
pair<ll,ll> str[N][2];
map<pair<pair<ll,ll>,pair<ll,ll> >,vector<ll> > mp;
int n,q;
string s[N][2];
struct Hash{
	pair<ll,ll> h[M]; int siz;
	void init(string s){
		siz=s.size();
		for(int i=0;i<siz;++i){
			h[i+1].first=(h[i].first*base1%mod1+s[i]-'a')%mod1;
			h[i+1].second=(h[i].second*base2%mod2+s[i]-'a')%mod2;
		}
	}
	pair<ll,ll> substr(int l,int r){
		return make_pair((h[r].first-h[l-1].first*b1[r-l+1]%mod1+mod1)%mod1,
						 (h[r].second-h[l-1].second*b2[r-l+1]%mod2+mod2)%mod2);
	}
}tmp,tmp1,tmp2;
void init(){
	b1[0]=b2[0]=1;
	for(int i=1;i<=M-10;++i){
		b1[i]=b1[i-1]*base1%mod1;
		b2[i]=b2[i-1]*base2%mod2;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	init();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
		tmp.init(s[i][0]);
		str[i][0]=tmp.h[tmp.siz];
		int j;
		for(j=0;j<tmp.siz;++j) if(s[i][0][j]!=s[i][1][j]) break;
		int k=tmp.siz-1;
		for(;k>=0;--k) if(s[i][0][k]!=s[i][1][k]) break;
		pair<ll,ll> s1=tmp.substr(j+1,k+1);
		tmp.init(s[i][1]);
		str[i][1]=tmp.h[tmp.siz];
		pair<ll,ll> s2=tmp.substr(j+1,k+1);
		mp[make_pair(s1,s2)].push_back(i);
		len[i]=j;
	}
	while(q--){
		string t1,t2; cin>>t1>>t2;
		if(t1.size()!=t2.size()) { puts("0"); continue; }
		int m=t1.size(),j,k;
		for(j=0;j<m;++j) if(t1[j]!=t2[j]) break;
		for(k=m-1;k>=0;--k) if(t1[k]!=t2[k]) break;
		tmp1.init(t1), tmp2.init(t2);
		int ans=0;
		for(auto i:mp[make_pair(tmp1.substr(j+1,k+1),tmp2.substr(j+1,k+1))]){
//			cout<<i<<" "<<j+1-len[i]<<" "<<j-len[i]+s[i][0].size()<<endl;
			if(j+1-len[i]<1 || j-len[i]+s[i][0].size()>m) continue;
			if(str[i][0]==tmp1.substr(j+1-len[i],j-len[i]+s[i][0].size())
			&& str[i][1]==tmp2.substr(j+1-len[i],j-len[i]+s[i][0].size()))
				++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}