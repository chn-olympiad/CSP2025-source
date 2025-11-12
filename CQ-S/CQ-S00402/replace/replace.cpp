#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=1e9+7,P=131,MAXN=2e5+5;
int n,q;
int pw[MAXN];
vector<pair<int,int>>v;
int ha[MAXN],hb[MAXN],length[MAXN];
int sha(int l,int r){
	if(r<l)return 0;
	return (ha[r]-(ha[l-1]*pw[r-l+1]))%mod+mod%mod;
}
int shb(int l,int r){
	if(r<l)return 0;
	return (hb[r]-(hb[l-1]*pw[r-l+1]))%mod+mod%mod;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=2e5;i++){
		pw[i]=(pw[i-1]*P)%mod;
	}
	scanf("%lld %lld",&n,&q);
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int h1=0,h2=0;
		length[i]=s1.size();
		for(auto x:s1) h1=(h1*P+x)%mod;
		for(auto x:s2) h2=(h2*P+x)%mod;
		v.push_back({h1,h2});
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size();
		for(int i=1;i<=len;i++) ha[i]=(ha[i-1]*P+s1[i-1])%mod;
		for(int i=1;i<=len;i++) hb[i]=(hb[i-1]*P+s2[i-1])%mod;
		int ans=0;
		for(int l=1;l<=len;l++){
			for(int j=1;j<=n;j++){
				int r=l+length[j]-1;
				if(r>len)continue;
				if(sha(1,l-1)==shb(1,l-1)&&sha(r+1,len)==shb(r+1,len)&&sha(l,r)==v[j-1].first&&shb(l,r)==v[j-1].second){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
