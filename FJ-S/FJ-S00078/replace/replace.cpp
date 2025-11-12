#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll base=137,mod=998244353,N=5000005,N2=2500005;
ll n,q,hsh[N],hsh2[N],sum1[N],sum2=0,d[N],ans[N],cnt3;
struct node{
	ll r1,r2,id;
	friend bool operator<(node x,node y){
		if(x.r1!=y.r1)return x.r1<y.r1;
		return x.r2<y.r2; 
	}
};
map<pair<ll,ll>,bool> mp;
string s1[N],s2[N];
vector<pair<ll,ll> > cnt2[N];
vector<node> H[N];
int lowbit(int x){
	return x&(-x);
}
void add(int x,ll k){
	while(x<=N2){
		d[x]+=k;
		x+=lowbit(x);
	}
}
ll query(int x){
	ll sum0=0;
	while(x){
		sum0+=d[x];
		x-=lowbit(x);
	}
	return sum0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n>>q;
	for(int i=1;i<=n;i++){
		cin >>s1[i]>>s2[i];
		ll l=s1[i].length(),h1=0,h2=0;
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
		for(int j=1;j<=l;j++){
			h1=(h1*base%mod+s1[i][j]-'a'+1)%mod;
			h2=(h2*base%mod+s2[i][j]-'a'+1)%mod;
		}
		sum2+=l;
		mp[{h1,h2}]=1;
//		cout <<h1<<" "<<h2<<"\n"; 
	}
	if(sum2>2000){
		for(int i=1;i<=n;i++){
			ll l=s1[i].length()-1;
			ll pos1=0,pos2=0;
			for(int j=1;j<=l;j++){
				if(s1[i][j]=='b')pos1=j;
				if(s2[i][j]=='b')pos2=j;
			}
			cnt2[pos1-pos2+N2].push_back({pos1,l-pos1+1});
		}
		for(int i=1;i<=q;i++){
			string t1,t2;
			cin >>t1>>t2;
			if(t1.length()!=t2.length()){
				cout <<0<<"\n";
				continue;
			}
			ll m=t1.length();
			t1=" "+t1;
			t2=" "+t2;
			ll pos1=0,pos2=0;
			for(int j=1;j<=m;j++){
				if(t1[j]=='b')pos1=j;
				if(t2[j]=='b')pos2=j;
			}
			H[pos1-pos2+N2].push_back({pos1,m-pos1+1,i});
		}
		for(int i=0;i<N;++i){
			sort(cnt2[i].begin(),cnt2[i].end());
			sort(H[i].begin(),H[i].end());
			ll j2=0;
			if(!cnt2[i].size())continue;
			for(int j=0;j<H[i].size();j++){
				ll r1=H[i][j].r1,r2=H[i][j].r2,id=H[i][j].id;
				while(j2<cnt2[i].size()&&cnt2[i][j2].first<=r1){
					add(cnt2[i][j2].second,1);
					++j2;
				}
				ans[id]=query(r2);
			}
			for(int j=0;j<j2;j++){
				add(cnt2[i][j].second,-1);
			}
		}
		for(int i=1;i<=q;i++)cout <<ans[i]<<"\n";
		return 0;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin >>t1>>t2;
		if(t1.length()!=t2.length()){
			cout <<0<<"\n";
			continue;
		}
		ll m=t1.length();
		t1=" "+t1;
		t2=" "+t2;
		ll ans=0;
		for(int j=1;j<=m;j++){
			sum1[j]=sum1[j-1]+(t1[j]!=t2[j]);
		}
		for(int j=1;j<=m;j++){
			ll h1=0,h2=0;
			if(sum1[j-1])continue;
			for(int k=j;k<=m;k++){
				h1=(h1*base%mod+t1[k]-'a'+1)%mod;
				h2=(h2*base%mod+t2[k]-'a'+1)%mod;
				if(sum1[m]-sum1[k])continue;
//				cout <<j<<" "<<k<<" "<<h1<<" "<<h2<<"\n";
				if(mp.count({h1,h2}))++ans;
			}
		}
		cout <<ans<<"\n";
	}
}
