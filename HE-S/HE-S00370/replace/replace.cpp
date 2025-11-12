#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second 
using namespace std;
const int N=2e5+5;
const int mod = 1e9+7;
const int base = 13131;
const int M=5e6+5; 
int n,q;
struct node{
	string s,t;
	int len; 
	bool operator < (const node &x) const {
		return len<x.len;
	}
};
node s[N],qn[N];
unordered_map<int,vector<int> > m;
inline int gethash(string s){
	int res=0;
	for(int i=0;s[i];++i){
		res=(1ll*res*base%mod+s[i])%mod; 
	}
	return res;
}
int pw[M];
int hs1[M],hs2[M];
inline int gethash1(int l,int r){
	return (hs1[r]-(l?(1ll*hs1[l-1]*pw[r-l+1]):0)%mod+mod)%mod;
} 
inline int gethash2(int l,int r){
	return (hs2[r]-(l?(1ll*hs1[l-1]*pw[r-l+1]):0)%mod+mod)%mod;
} 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	bool flag=1;
	pw[0]=1;
	for(int i=1;i<M;++i){
		pw[i]=1ll*pw[i-1]*base%mod;
	}
	for(int i=1;i<=n;++i){
		cin>>s[i].s>>s[i].t;
		s[i].len=s[i].s.size();
	}
	for(int i=1;i<=q;++i){
		cin>>qn[i].s>>qn[i].t; 
		qn[i].len=qn[i].s.size();
	}           
		for(int i=1;i<=n;++i){
			int t1=gethash(s[i].s),t2=gethash(s[i].t);
			m[t1].push_back(t2);
		}
		for(int i=1;i<=q;++i){
			int l=-1;
			while(qn[i].s[l+1]==qn[i].t[l+1]) ++l;
			int r=qn[i].len;
			while(qn[i].s[r-1]==qn[i].t[r-1]) --r;
			for(int j=0;j<qn[i].len;++j){
				hs1[j+1]=(1ll*hs1[j]*base%mod+qn[i].s[j])%mod;
			}
			for(int j=0;j<qn[i].len;++j){
				hs2[j+1]=(1ll*hs2[j]*base%mod+qn[i].t[j])%mod;
			}
			int ans=0;
			for(int j=-1;j<=l;++j){
				for(int k=max(j+2,r);k<=qn[i].len;++k){
					int temp=gethash2(j+2,k);
					for(auto x:m[gethash1(j+2,k)]){
						if(x==temp) ++ans;
					}
				}
			}
			cout<<ans<<endl;
		}
	return 0;
}
