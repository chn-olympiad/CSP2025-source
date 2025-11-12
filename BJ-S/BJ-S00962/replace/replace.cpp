#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int M=5e6+5;
const int mod1=1e9+7;
const int mod2=998244353;
const int base1=9973;
const int base2=9967;
int n,q;
int lens[N];
long long p1[M],p2[M];
pair<long long,long long> hs1[N],hs2[N],ht1[M],ht2[M];
pair<long long,long long> hash1(int l,int r){
	if(l>r) return make_pair(0,0);
	pair<long long,long long> res;
	res.first=(ht1[r].first-ht1[l-1].first*p1[r-l+1]%mod1+mod1)%mod1;
	res.second=(ht1[r].second-ht1[l-1].second*p2[r-l+1]%mod2+mod2)%mod2;
	return res;
}
pair<long long,long long> hash2(int l,int r){
	if(l>r) return make_pair(0,0);
	pair<long long,long long> res;
	res.first=(ht2[r].first-ht2[l-1].first*p1[r-l+1]%mod1+mod1)%mod1;
	res.second=(ht2[r].second-ht2[l-1].second*p2[r-l+1]%mod2+mod2)%mod2;
	return res;	
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	p1[0]=p2[0]=1;
	for(int i=1;i<M;i++){
		p1[i]=p1[i-1]*base1%mod1,p2[i]=p2[i-1]*base2%mod2;
	}
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size();
		s1=" "+s1,s2=" "+s2,lens[i]=len;
		pair<long long,long long> h1={0,0},h2={0,0};
		for(int j=1;j<=len;j++){
			h1.first=(h1.first*base1%mod1+s1[j]-'a'+1)%mod1;
			h1.second=(h1.second*base2%mod2+s1[j]-'a'+1)%mod2;
			h2.first=(h2.first*base1%mod1+s2[j]-'a'+1)%mod1;
			h2.second=(h2.second*base2%mod2+s2[j]-'a'+1)%mod2;			
		}
		hs1[i]=h1,hs2[i]=h2;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int len=t1.size(),ans=0;
		t1=" "+t1,t2=" "+t2;
		for(int i=1;i<=len;i++){
			ht1[i].first=(ht1[i-1].first*base1%mod1+t1[i]-'a'+1)%mod1;
			ht1[i].second=(ht1[i-1].second*base2%mod2+t1[i]-'a'+1)%mod2;
			ht2[i].first=(ht2[i-1].first*base1%mod1+t2[i]-'a'+1)%mod1;
			ht2[i].second=(ht2[i-1].second*base2%mod2+t2[i]-'a'+1)%mod2;
		}
		for(int i=1;i<=n;i++){
			bool flag=0;
			for(int j=1;j+lens[i]-1<=len;j++){
				if(hash1(j,j+lens[i]-1)==hs1[i]){
					if(hash2(j,j+lens[i]-1)==hs2[i]){
						if(hash1(1,j-1)==hash2(1,j-1)){
							if(hash1(j+lens[i],len)==hash2(j+lens[i],len)){
								flag=1;break;
							}
						}
					}
				}
			}
			ans+=flag;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
