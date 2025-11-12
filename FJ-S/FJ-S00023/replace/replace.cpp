#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c>57||c<48){if(c==45)f=-1;c=getchar();}
	while(c<=57&&c>=48){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
typedef pair<int,int> PII;
const int N=2002,P=1e9+7,D=31;
char a[N][N],b[N][N],s[N],t[N];
map<int,int> mp;
int hs[N][N][2],L[N],R[N],lan[N];
int n,Q,M[N],ls[N],tot;
vector <PII> G[N];
void solve(){
	M[0]=1;
	for(int i=1;i<=2002;++i)M[i]=M[i-1]*D%P;
	n=read();Q=read();
	for(int i=1;i<=n;++i){
		scanf("%s",a+1);
		scanf("%s",b+1);
		int len=strlen(a+1);lan[i]=len;
		for(int j=1;j<=len;++j){
			hs[i][j][0]=(hs[i][j-1][0]*D%P+a[i][j])%P;
			hs[i][j][1]=(hs[i][j-1][1]*D%P+b[i][j])%P;
		}
		
		int l=1;
		while(a[l]==b[l]&&l<=len)++l;
		int r=len;
		while(a[r]==b[r]&&r>=1)--r;
		if(l>r)continue;
		L[i]=l;R[i]=r;
//		int z=0,H=0;
//		for(int j=l;j<=r;++j){
//			z=(z*D%P+b[j])%P;
//			H=(H*D%P+a[j])%P;
//		}
//		if(!mp[z])mp[z]=++tot;
//		
//		int r=mp[z];
//		G[r].push_back({H,i});
		
	}
	while(Q--){
		scanf("%s",a+1);
		scanf("%s",b+1);
		int len=strlen(a+1);
		if(len!=strlen(b+1)){puts("0");continue;}
		int A=0;
		for(int j=1;j<=len;++j){
			A=(A*D%P+s[j])%P;
		}
		
		int l=1;
		while(s[l]==t[l]&&l<=len)++l;
		int r=len;
		while(s[r]==t[r]&&r>=1)--r;
//		int z=0,H=0;
//		for(int j=l;j<=r;++j){
//			z=(z*D%P+t[j])%P;
//			H=(H*D%P+s[j])%P;
//		}
//		if(!mp[z]){
//			puts("0");continue;
//		}
//		int RR=mp[z]
//		for(auto p:G[RR]){
//			int ch=p.first,id=p.second;
//			
//		}
		for(int i=1;i<=n;++i){
			int can=1;
			if(R[i]==0||L[i]!=l||R[i]!=r)can=0;
			for(int j=1;j<=r-l+1;++j){
				if(s[l+j-1]!=a[i][L[i]+j-1])can=0;
				if(t[l+j-1]!=b[i][L[i]+j-1])can=0;
			}
			if(L[i]<l)continue;
			if((lan[i]-R[i])<(len-r))continue;
			for(int j=1;j<L[i];++j){
				if(s[l-j]!=a[i][L[i]-j]){
					can=0;break;
				}
			}
			for(int j=1;j<(len-R[i]);++j){
				if()
			}
		}
		
		
		
	}
}
signed main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	int ttt=1;while(ttt--)solve();
	return 0;
}
