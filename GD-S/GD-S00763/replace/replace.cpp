#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2*1e5+1e3,base=13331,mod=1e9+7,M=2*1e6+1e5;
int n,m;

ll h1[N];
ll h2[N];
ll sl[N];
ll ghash(string &s){
	int len=s.size();
	ll ret=0;
	for(int i=0;i<len;i++){
		ret=ret*base%mod+s[i]-'a';
		ret%=mod;
	}	
	return ret;
}
ll z1[M],z2[M];
void gzhash(string &s,ll* z){
	int len=s.size();
	ll ret=0;
	for(int i=0;i<len;i++){
		ret=ret*base%mod+s[i]-'a';
		ret%=mod;
		z[i+1]=ret;
	}	
}
ll bpw[M];
void init(){
	bpw[0]=1;
	for(int i=1;i<M;i++) bpw[i]=(bpw[i-1]*base)%mod; 
}
ll gt(ll* z,int l,int r){
	return ((z[r]-z[l]*bpw[r-l])%mod+mod)%mod;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	init();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		h1[i]=ghash(s1);h2[i]=ghash(s2);
		sl[i]=s1.size();
	}
	for(int o=1;o<=m;o++){
		string s1,s2;
		cin>>s1>>s2;
		gzhash(s1,z1);
		gzhash(s2,z2);
		int len1=s1.size(),len2=s2.size();
		if(len1!=len2){
			cout<<0<<endl;
		}
		else{
			int cnt=0;
			for(int i=1;i<=len1;i++){
				for(int j=1;j<=n;j++){
					if(i+sl[j]-1>len1) continue;
					if(gt(z1,i-1,i+sl[j]-1)==h1[j] && gt(z2,i-1,i+sl[j]-1)==h2[j]){
						if(z1[i-1]==z2[i-1] && gt(z1,i+sl[j]-1,len1)==gt(z2,i+sl[j]-1,len1)) ++cnt;
					}
				}
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}
