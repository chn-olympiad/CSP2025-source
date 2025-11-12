#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005,MAXM=5000005,base=131,mod=998244353,mod1=1145141;
long long dp[MAXN],n,q;
string s1[MAXN],s2[MAXN],t1,t2;
map<pair<long long,long long> ,long long>ma;
long long hs1[MAXN],hs2[MAXN],p[MAXN];
void hs(int len){
	p[0]=1;
	for(int i=1;i<=len;i++)p[i]=(p[i-1]*base)%mod;
	hs1[0]=hs2[0]=0;
	for(int i=1;i<=len;i++){
		hs1[i]=(hs1[i-1]*base+mod+t1[i])%mod;
		hs2[i]=(hs2[i-1]*base+mod+t2[i])%mod;
	}
}
long long get_hash(int l,int r){
	return (hs1[r]-hs1[l-1]*p[r-l+1]%mod+mod)%mod;
}
long long get_hash2(int l,int r){
	return (hs2[r]-hs2[l-1]*p[r-l+1]%mod+mod)%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		long long len=s1[i].length(),hs,hs2;
		hs=s1[i][0];
		hs2=s2[i][0];
		for(int j=1;j<len;j++){
			hs=(hs*base+mod+s1[i][j])%mod;
			hs2=(hs2*base+mod+s2[i][j])%mod;
		}
		//cout<<hs<<" "<<hs2<<endl;
		ma[make_pair(hs,hs2)]++;
	}
	while(q--){
		cin>>t1>>t2;
		t1=" "+t1;
		t2=" "+t2;
		int n=t1.length()-1;
		hs(n);
		int l=-1,r=-1;
		for(int i=1;i<=n;i++){
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		}
		for(int i=n;i>=1;i--){
			if(t1[i]!=t2[i]){
				r=i;
				break;
			}
		}
		long long ans=0;
		if(s1==s2){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					long long h1=get_hash(i,j),h2=get_hash2(i,j);
					ans+=ma[make_pair(h1,h2)];
				}
			}
		}else{
			for(int i=1;i<=l;i++){
				for(int j=r;j<=n;j++){
					long long h1=get_hash(i,j),h2=get_hash2(i,j);
					ans+=ma[make_pair(h1,h2)];
					//cout<<i<<" "<<j<<" "<<h1<<" "<<h2<<" "<<ma[make_pair(h1,h2)]<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
