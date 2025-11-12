#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7,base=13331,B=598004655;
const int N=2e5+5,M=5e6+5;
int n,q;
string s1,s2;
ll a[N],len[N];
ll x[N],y[N],f[M],g[M];
ll sum1[N],sum2[N];
vector<int>id[30][30];
ll quick_pow(ll a,ll b,ll mod){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll queryx(int l,int r){
	return ((x[r]-x[l-1]*f[r-l+1])%mod+mod)%mod;
}
ll queryy(int l,int r){
	return ((y[r]-y[l-1]*f[r-l+1])%mod+mod)%mod;
}
//bool isp(long long x){
//	for(long long i=2;i*i<=x;i++){
//		if(x%i==0) return false;
//	}
//	return true;
//}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	f[0]=g[0]=1;
	for(int i=1;i<=M-5;i++){
		f[i]=f[i-1]*base%mod;
		g[i]=g[i-1]*B%mod; //ÄæÔª 
	}
	for(int i=1;i<=n;i++){
		ll h1=0,h2=0;
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++) h1=(h1*base+s1[j])%mod;
		for(int j=0;j<s2.size();j++) h2=(h2*base+s2[j])%mod;
		a[i]=(h1+h2)%mod;
		len[i]=s1.size();
		id[s1[s1.size()-1]-'a'][s2[s2.size()-1]-'a'].push_back(i);
	}
	while(q--){
		cin>>s1>>s2;
		int lens=s1.size(); 
		long long ans=0;
		s1=' '+s1,s2=' '+s2;
		y[0]=x[0]=0;
		for(int i=1;i<=lens;i++) x[i]=(x[i-1]*base+s1[i])%mod;
		for(int i=1;i<=lens;i++) y[i]=(y[i-1]*base+s2[i])%mod;
		int pos=0;
		for(int i=1;i<=lens;i++){
			if(i<lens&&queryx(i+1,lens)!=queryy(i+1,lens)) continue;
			for(int v:id[s1[i]-'a'][s2[i]-'a']){
				if(len[v]>i) continue;
				int l=i-len[v]; 
				if(x[l]==y[l]&&queryx(i+1,lens)==queryy(i+1,lens)&&queryx(l+1,i)+queryy(l+1,i)==a[v]) ans++;
			} 
		}
		cout<<ans<<'\n';
	}
	return 0;
}
