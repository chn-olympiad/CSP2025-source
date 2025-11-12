#include<bits/stdc++.h>
#define eps 1e-6
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
#define fi first
#define se second
#define MOD 998244353
#define MAXN 300005
#define MXL 5000005
int n,Q;
string s[MAXN][2],t[2];
const LL B1=100003,B2=10000007;
const LL M1=998244353,M2=1000000007;
// LL hs1[MAXN][2],hs2[MAXN][2];
// LL has1[2][MXL],has2[2][MXL];
namespace Sub{
LL hsl[MAXN],hsr[MAXN],hs[MAXN][2];
LL hasl[MXL],hasr[MXL],has[2];
void work(){
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		int l=0,r=s[i][0].size()-1;
		while(l<=r&&s[i][0][l]==s[i][1][l])
			l++;
		while(l<=r&&s[i][0][r]==s[i][1][r])
			r--;
		if(l>r)continue;
		// cout<<l<<' '<<r<<'\n';
		for(int _=0;_<=1;_++){
			for(int j=l;j<=r;j++){
				int c=s[i][_][j]-'a'+1;
				hs[i][_]=(hs[i][_]*B1%M1+c)%M1;
			}
		}
		for(int j=0;j<l;j++){
			int c=s[i][0][j]-'a'+1;
			hsl[i]=(hsl[i]*B1%M1+c)%M1;
		}
		for(int j=(int)s[i][0].size()-1;j>r;j--){
			int c=s[i][0][j]-'a'+1;
			hsr[i]=(hsr[i]*B1%M1+c)%M1;
		}
		// cout<<hsl[i]<<' '<<hsr[i]<<' ';
		// cout<<hs[i][0]<<' '<<hs[i][1]<<'\n';
	}
	while(Q--){

	cin>>t[0]>>t[1];
	if(t[0].size()!=t[1].size()){
		puts("0");continue;
	}
	int l=0,r=t[0].size()-1;
	while(l<=r&&t[0][l]==t[1][l])
		l++;
	while(l<=r&&t[0][r]==t[1][r])
		r--;
	for(int _=0;_<=1;_++){
		has[_]=0;
		for(int j=l;j<=r;j++){
			int c=t[_][j]-'a'+1;
			has[_]=(has[_]*B1%M1+c)%M1;
		}
		// cout<<has[_]<<' ';
	}
	// cout<<'\n';
	hasl[l]=hasr[r]=0;
	unordered_map<LL,bool>mpl,mpr;mpl[0]=mpr[0]=1;
	LL Base=1;
	for(int i=l-1;i>=0;i--){
		int c=t[0][i]-'a'+1;
		hasl[i]=(hasl[i+1]+c*Base%M1)%M1;
		mpl[hasl[i]]=1;
		// cout<<hasl[i]<<'\n';
		Base=Base*B1%M1;
	}
	// cout<<'\n';
	Base=1;
	for(int i=r+1;i<(int)t[0].size();i++){
		int c=t[0][i]-'a'+1;
		hasr[i]=(hasr[i-1]+c*Base%M1)%M1;
		mpr[hasr[i]]=1;
		// cout<<hasr[i]<<'\n';
		Base=Base*B1%M1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(has[0]==hs[i][0]&&has[1]==hs[i][1]
			&&mpl.count(hsl[i])&&mpr.count(hsr[i]))
			ans++;
	}
	printf("%d\n",ans);
}
}
}
signed main(){
	// auto ST=clock();
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	if(Q==1||1){
		Sub::work();
		// auto EN=clock();
		// cerr<<(LD)(EN-ST)/CLOCKS_PER_SEC<<'\n';
		return 0;
	}
	// for(int i=1;i<=n;i++){
	// 	cin>>s[i][0]>>s[i][1];
	// 	int l=s[i][0].size();
	// 	for(int _=0;_<=1;_++){
	// 		for(int j=0;j<l;j++){
	// 			int c=s[i][_][j]-'a'+1;
	// 			hs1[i][_]=(hs1[i][_]*B1%M1+c)%M1;
	// 			hs2[i][_]=(hs2[i][_]*B2%M2+c)%M2;
	// 		}
	// 	}
	// }
	// while(Q--){
	// 	cin>>t[0]>>t[1];
	// 	if(t[0].size()!=t[1].size()){
	// 		puts("0");
	// 		continue;
	// 	}
	// 	int l=t[0].size();
	// 	for(int _=0;_<=1;_++){
	// 		for(int j=0;j<l;j++){
	// 			int c=t[_][j]-'a'+1;
	// 			has1[_][j]=((!j?0:has1[_][j-1])*B1%M1+c)%M1;
	// 			has2[_][j]=((!j?0:has2[_][j-1])*B2%M2+c)%M2;
	// 		}
	// 	}
	// 	for(int j=0;j<l;j++){
	// 		;
	// 	}
	// }

	return 0;
}