#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
} 
const int base=131,mod=1e9+7,N=2e5+5,len=5e6+5;
int h1[N],h2[N],b[len];
string s1[N],s2[N],t1,t2;
int h3[len],h4[len];
int hashe(string s){
	int res=0;
	for(int i=0;i<s.size();i++){
		res=(res*base%mod+s[i])%mod;
	}
	return res;
}
void init(){
	b[0]=1;
	for(int i=1;i<=5000000;i++){
		b[i]=b[i-1]*base%mod;
	}
}
int ghash1(int l,int r){
	return (h3[r]-h3[l-1]*b[r-l+1]%mod)%mod;
}
int ghash2(int l,int r){
	return (h4[r]-h4[l-1]*b[r-l+1]%mod)%mod;
}
int n,q,ans;
void dfs(int now){
	if(now>=t1.size()){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=now;j<=t1.size();j++){
			if(j+s1[i].size()-1>t1.size()) continue;

			if(ghash1(j,j+s1[i].size()-1)==h1[i]&&h2[i]==ghash2(j,j+s2[i].size()-1)){
				j+=s1[i].size()-1;
				dfs(j+1);
				j-=s1[i].size()-1;
			}
		}
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	init();
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		h1[i]=hashe(s1[i]);
		h2[i]=hashe(s2[i]);	
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		for(int i=0;i<t1.size();i++){
			h3[i+1]=(h3[i]*base%mod+t1[i])%mod;
		}
		for(int i=0;i<t2.size();i++){
			h4[i+1]=(h4[i]*base%mod+t2[i])%mod;
		}
		ans=0;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}

