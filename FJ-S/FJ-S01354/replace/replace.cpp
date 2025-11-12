#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define ll long long
#define R(a,b,c) for(ll a=b;a<=c;a++)
#define E(a,b,c) for(ll a=b;a>=c;a--)
using namespace std;
string s1[400025];
vector<ll> hs1[400025];
string s2[400025];
vector<ll> hs2[400025];
ll len[400025];
ll bs=37;
ll tt[400025];
map<pair<ll,ll>,ll> mp;
const ll mod=201202297;
inline ll fp(ll a,ll b){
	a%=mod;
	ll ans=1;
	while(b){
		if(b&1)(ans*=a)%=mod;
		(a*=a)%=mod;
		b>>=1;
	}
	return ans;
}
inline ll get1(ll i,ll l,ll r){
	return (hs1[i][r]-hs1[i][l-1]*fp(bs,r-l+1)%mod+mod)%mod;
}
inline ll get2(ll i,ll l,ll r){
	return (hs2[i][r]-hs2[i][l-1]*fp(bs,r-l+1)%mod+mod)%mod;
}
ll p[400025];
bool cmp(const ll& a,const ll&b){
	return len[a]<len[b];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,q;
	cin>>n>>q;
	R(i,1,n){
		cin>>s1[i]>>s2[i];
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
		len[i]=s1[i].length()-1;
		hs1[i].reserve(len[i]+1);
		hs1[i].push_back(0);
		hs2[i].reserve(len[i]+1);
		hs2[i].push_back(0);
		R(j,1,len[i]){
			hs1[i].push_back((hs1[i][j-1]*bs+s1[i][j]-'a'+1)%mod);
			hs2[i].push_back((hs2[i][j-1]*bs+s2[i][j]-'a'+1)%mod);
		}
		mp[{hs1[i][len[i]],hs2[i][len[i]]}]++;
		p[i]=i;
		tt[i]=len[i];
	}
	sort(tt+1,tt+1+n);
	ll tlen=unique(tt+1,tt+1+n)-tt-1;
	sort(p+1,p+1+n,cmp);
	R(i,1,q){
		string a,b;
		cin>>a>>b;
		a=" "+a;
		b=" "+b;
		ll tl=a.length()-1;
		len[i+n]=tl;
		hs1[i+n].reserve(len[i+n]+1);
		hs1[i+n].push_back(0);
		hs2[i+n].reserve(len[i+n]+1);
		hs2[i+n].push_back(0);
		R(j,1,len[i+n]){
			hs1[i+n].push_back((hs1[i+n][j-1]*bs+a[j]-'a'+1)%mod);
			hs2[i+n].push_back((hs2[i+n][j-1]*bs+b[j]-'a'+1)%mod);
		}
		ll L=1,R=tl;
		while(L<tl&&a[L]==b[L])L++;
		while(R>1&&a[R]==b[R])R--;
		if(L>R){
			ll ans=0;
			R(T1,1,tlen){
				ll ttl=tt[T1];
				R(I,1,L){
					ll J=I+ttl-1;
					if(J>tl)break;
					if(mp.count({get1(i+n,I,J),get2(i+n,I,J)}))ans+=mp[{get1(i+n,I,J),get2(i+n,I,J)}];
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		ll ans=0;
		ll l=0,r=tlen;
		while(l+1<r){
			ll mid=l+r>>1;
			if(tt[mid]>=R-L+1)r=mid;
			else l=mid;
		}
		R(T1,r,tlen){
			ll ttl=tt[T1];
			R(I,1,L){
				ll J=I+ttl-1;
				if(J<R)continue;
				if(J>tl)break;
				if(mp.count({get1(i+n,I,J),get2(i+n,I,J)}))ans+=mp[{get1(i+n,I,J),get2(i+n,I,J)}];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
