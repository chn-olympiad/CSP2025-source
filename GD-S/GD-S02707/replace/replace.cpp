#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int (i)=(x);(i)<=(y);(i)++)
#define REP(i,x,y) for(int (i)=(x);(i)>=(y);(i)--)
#define fastIO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
typedef unsigned long long ull;
const ull P=19260817;
const ull Q=998244353;
const int N=200003;
const int M=5000003;
int n,m;
string s[N][2];
ull S[N][2][2],pw[M][2],f[M][2],g[M][2];
ull Hash0(string Str){ int sz=Str.size(); ull ret=0;
	rep(i,0,sz-1){
		ret=ret*P+Str[i]-'a'+1;
	} return ret;
}
ull Hash1(string Str){ int sz=Str.size(); ull ret=0;
	rep(i,0,sz-1){
		ret=ret*Q+Str[i]-'a'+1;
	} return ret;
}
bool SAME(int x,int y){ int z=s[y][0].size();
	ull num1=f[x+z-1][0]-f[x-1][0]*pw[z][0];
	ull num2=f[x+z-1][1]-f[x-1][1]*pw[z][1];
	if(num1!=S[y][0][0]) return 0;
	if(num2!=S[y][0][1]) return 0;
	num1=g[x+z-1][0]-g[x-1][0]*pw[z][0];
	num2=g[x+z-1][1]-g[x-1][1]*pw[z][1];
	if(num1!=S[y][1][0]) return 0;
	if(num2!=S[y][1][1]) return 0;
	return 1;
}
int main(){ freopen("replace.in","r",stdin); freopen("replace.out","w",stdout); fastIO; cin>>n>>m;
	pw[0][0]=pw[0][1]=1; rep(i,1,n){ pw[i][0]=pw[i-1][0]*P; pw[i][1]=pw[i-1][1]*Q; }
	rep(i,1,n){ cin>>s[i][0]>>s[i][1];
		S[i][0][0]=Hash0(s[i][0]); S[i][0][1]=Hash1(s[i][0]);
		S[i][1][0]=Hash0(s[i][1]); S[i][1][1]=Hash1(s[i][1]);
	}
	string A,B; int L,R,ans;
	while(m--){ ans=0; cin>>A>>B; if(A.size()!=B.size()){ cout<<"0\n"; continue; } L=A.size(); R=0;
		rep(i,1,L){
			f[i][0]=f[i-1][0]*P+A[i-1]-'a'+1;
			f[i][1]=f[i-1][1]*Q+A[i-1]-'a'+1;
			g[i][0]=g[i-1][0]*P+B[i-1]-'a'+1; 
			g[i][1]=g[i-1][1]*Q+B[i-1]-'a'+1; 
		}
		rep(i,1,A.size()){
			if(A[i-1]!=B[i-1]) L=min(L,i),R=max(R,i);
		}
		rep(i,1,n){ if(L+s[i][0].size()<=R) continue;
			rep(j,max(1,int(R-s[i][0].size()+1)),L){ if(j+s[i][0].size()-1>A.size()) break;
				if(SAME(j,i)) ++ans;
			}
		} cout<<ans<<'\n';
	} return 0;
}
