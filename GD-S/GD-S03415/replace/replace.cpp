#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=5e6+10;
const long long mod=1e9+9,B=131;
string s[N][2];
long long b[M],H[N][2],H1[M],H2[M];
void init() {
	b[0]=1;
	for(int i=1;i<N;i++) b[i]=b[i-1]*B%mod;
}
long long get_hash(string s) {
	long long x=0;
	for(size_t i=0;i<s.length();i++) x=(x*B%mod+s[i])%mod;
	return x;
}
long long get_hash(long long hs[],int l,int r) {
	if(l>r) return 0;
	return (hs[r]-hs[l-1]*b[r-l+1]%mod+mod)%mod;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;init();
	for(int i=1;i<=n;i++) {
		cin>>s[i][0]>>s[i][1];
		H[i][0]=get_hash(s[i][0]),H[i][1]=get_hash(s[i][1]);
	}
	while(q--) {
		string t1,t2;cin>>t1>>t2;
		int leng=t1.length();t1=' '+t1;t2=' '+t2;
		for(int i=1;i<=leng;i++) H1[i]=(H1[i-1]*B%mod+t1[i])%mod,H2[i]=(H2[i-1]*B+t2[i])%mod;
		int ans=0;
		for(int i=1;i<=n;i++) {
			int len=s[i][0].length();
			for(int j=1;j+len-1<=leng;j++) {
				int k=j+len-1;long long t12=get_hash(H1,j,k);
				if(t12==H[i][0]) {
					long long t11=get_hash(H1,1,j-1),t13=get_hash(H1,k+1,leng);
					long long t21=get_hash(H2,1,j-1),t22=get_hash(H2,j,k),t23=get_hash(H2,k+1,leng);
					if(t11==t21&&t13==t23&&t22==H[i][1]) ans++;
				}	
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
