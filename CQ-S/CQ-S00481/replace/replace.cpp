#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,Q,g[200005],g2[200005],g3[200005],g4[200005],a[200005],cnt,tot,f[200005],f2[200005];
int base=131,mod=1e9+7,maxn=0,bs[5000006],ans,sum;
string s[200005],t[200005],S,T;
vector<int> v[200005];
map<int,int> mp;
struct node{
	int id,sum,cnt;
}o[200005];
inline int ksm(int A,int B){
	int res=1;
	while(B){
		if(B&1) res=(res*A)%mod;
		A=(A*A)%mod; B/=2; 
	}
	return res;
}
inline int get(int l,int r){
	return (f[r]-(f[l-1]*bs[r-l+1]%mod)+mod)%mod;
}
inline int get2(int l,int r){
	return (f2[r]-(f2[l-1]*bs[r-l+1]%mod)+mod)%mod;
}
int cmp(node x,node y){return x.sum<y.sum;}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i]; a[i]=s[i].size();
		s[i]=" "+s[i]; t[i]=" "+t[i];
		int fir=1,sec=a[i]; maxn=max(maxn,a[i]);
		for(int j=1;j<=a[i];j++){
			fir=j;
			if(s[i][j]!=t[i][j]) break;
		}
		for(int j=a[i];j>=1;j--){
			sec=j;
			if(s[i][j]!=t[i][j]) break;
		}
		for(int j=1;j<=a[i];j++){
			g[i]=(g[i]*base+(s[i][j]-'a'+1))%mod;
			g2[i]=(g2[i]*base+(t[i][j]-'a'+1))%mod;
		}
		for(int j=fir;j<=sec;j++){
			if(s[i][j]==t[i][j]) g3[i]=(g3[i]*base)%mod;
			else g3[i]=(g3[i]*base+1)%mod;
		}
		g4[i]=fir;
		if(mp[g3[i]]==0){
			sum++;
			mp[g3[i]]=sum;
			v[sum].push_back(i);
		}
		else v[mp[g3[i]]].push_back(i);
	}
	bs[0]=1;
	for(int i=1;i<=maxn;i++) bs[i]=(bs[i-1]*base)%mod;
	while(Q--){
		cin>>S>>T; cnt=S.size(),tot=0;
		S=" "+S; T=" "+T;
		int fir=1,sec=cnt; ans=0;
		for(int j=1;j<=cnt;j++){
			fir=j;
			if(S[j]!=T[j]) break;
		}
		for(int j=cnt;j>=1;j--){
			sec=j;
			if(S[j]!=T[j]) break;
		}
		for(int j=fir;j<=sec;j++){
			if(S[j]==T[j]) tot=(tot*base)%mod;
			else tot=(tot*base+1)%mod;
		}
		for(int j=0;j<=cnt;j++) f[j]=f2[j]=0;
		for(int j=1;j<=cnt;j++){
			f[j]=(f[j-1]*base+(S[j]-'a'+1))%mod;
			f2[j]=(f2[j-1]*base+(T[j]-'a'+1))%mod;
		}
		if(mp[tot]==0) ans=0;
		else {
			int M=mp[tot],N=v[M].size();
			for(int j=0;j<N;j++){
				int i=v[M][j],l=fir-g4[i]+1,r=l+a[i]-1;
				if(l<1 || r>cnt) continue;
				if(get(l,r)==g[i] && get2(l,r)==g2[i]) ans++;
			}
		}
//		for(int i=1;i<=n;i++){
//			if(g3[i]!=tot) continue;
//			int l=fir-g4[i]+1,r=l+a[i]-1;
//			if(l<1 || r>cnt) continue;
//			if(get(l,r)==g[i] && get2(l,r)==g2[i]) ans++;
//		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
