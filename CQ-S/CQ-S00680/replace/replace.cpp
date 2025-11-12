#include<bits/stdc++.h> 
#define int long long 
#define x first 
#define y second 
#define il inline 
#define eb emplace_back 
#define debug() puts("-----") 
using namespace std; 
typedef pair<int,int> pii; 
il int read(){ 
	int x=0,f=1; char ch=getchar(); 
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } 
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar(); 
	return x*f; 
} 
const int mod=1e9+7,tim=233; 
const int N=2e5+10,M=5e6+10; 
int n,q; 
int b[M]; 
int mp[M]; 
int len[N]; 
int Hs1[M],Hs2[M]; 
string s1[N],s2[N]; int idp; 
vector<int> hs1[N],hs2[N]; 
il int get1(int l,int r){ 
	return (hs1[idp][r]-hs1[idp][l-1]*b[r-l+1]%mod+mod)%mod; 	
} 
il int get2(int l,int r){ 
	return (hs2[idp][r]-hs2[idp][l-1]*b[r-l+1]%mod+mod)%mod; 
} int ln; 
il int g1(int l,int r){ 
	if(l<1||r>ln) return -1; 
	return (Hs1[r]-Hs1[l-1]*b[r-l+1]%mod+mod)%mod; 	
} 
il int g2(int l,int r){ 
	if(l<1||r>ln) return -1; 
	return (Hs2[r]-Hs2[l-1]*b[r-l+1]%mod+mod)%mod; 
} 
il void sol1(){ 
	string t1,t2; 
	cin>>t1>>t2; int ans=0; ln=t1.size(); 
	t1=" "+t1,t2=" "+t2; 
	if(t1.size()!=t2.size()){ 
		puts("0"); 
		return ; 
	} int l=1e9,r=0; string str1=" ",str2=" "; 
	for(int i=1;i<=ln;i++) if(t1[i]!=t2[i]) l=min(l,i),r=i; 
	int Len=r-l+1; 
	for(int i=1;i<=ln;i++){ 
		Hs1[i]=(Hs1[i-1]*tim%mod+(int)t1[i])%mod; 
		Hs2[i]=(Hs2[i-1]*tim%mod+(int)t2[i])%mod; 
	} //cout<<l<<" "<<r<<endl; 
	for(int i=1;i<=n;i++){ 
		if(len[i]>=Len&&len[i]<=ln){ 
			idp=i; 
			for(int j=1;j<=len[i]-Len+1;j++){
				if(get1(j,j+Len-1)==g1(l,r)&&get2(j,j+Len-1)==g2(l,r)){ 
					if(hs1[idp][len[i]]==g1(l-j+1,r+(len[i]-(j+Len-1)+1)-1)){
						if(hs2[idp][len[i]]==g2(l-j+1,r+(len[i]-(j+Len-1)+1)-1))ans++; 
					}
				} 
			}
		} 
	} printf("%lld\n",ans); 
} 
int cs[N]; 
int tot=0; 
map<int,int> Mp,tr[N]; 
#define low(x) x&-x 
il void add(int id,int x){ 
	for(int i=x;i<=n;i+=low(i)) tr[id][i]++; 	
} 
il int qry(int id,int x){
	int res=0; 
	for(int i=x;i;i-=low(i)) res+=tr[id][i]; 
	return res; 
}
signed main(){ 
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout); 
	b[0]=1; for(int i=1;i<M;i++) b[i]=b[i-1]*tim%mod; 
	n=read(),q=read(); 
	for(int i=1;i<=n;i++){ 
		cin>>s1[i]>>s2[i]; 
		len[i]=s1[i].size(); 
		s1[i]=" "+s1[i],s2[i]=" "+s2[i]; 
		hs1[i].resize(len[i]+1); 
		hs2[i].resize(len[i]+1); 
		for(int j=1;j<=len[i];j++){ 
			hs1[i][j]=(hs1[i][j-1]*tim%mod+(int)s1[i][j])%mod; 
			hs2[i][j]=(hs2[i][j-1]*tim%mod+(int)s2[i][j])%mod; 
		} 
	} while(q--) sol1(); 
	return 0; 
	
} /*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex

*/
