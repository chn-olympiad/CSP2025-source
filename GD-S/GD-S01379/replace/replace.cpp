#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) x.begin(), x.end()

#ifdef DEBUG
void DD(){cerr<<endl;}
template<typename A,typename...B>void DD(A a,B...b){cerr<<a<<" ",DD(b...);}
#define debug(x...) cerr<<"["<<#x<<"]: ", DD(x)
//#define debug(...) (void)11
#else
#define debug(...) (void)11
#endif
constexpr int N=2e5+10,NN=5e6+5;
string s[2][N],t[2],al[2];
int n,q,nn;
int L[N];
int nxt[NN];
bitset<NN>vis;
int ed[N],bl[N];
int solve(int l,int r){
//	int M=r-l+1,res=0; 
//	for(int i=2,j=0; i<=M; i++){
//		while(j&&t[0][l+i-1]!=t[0][l+j]) j=nxt[j];
//		if(t[0][l+i-1]==t[0][l+j]) j++;
//		nxt[i]=j;
//	}
//	vector<int>p;
//	for(int i=1,j=0; i<=nn; i++){
//		while(j&&al[0][i]!=t[0][l+j]) j=nxt[j];
//		if(al[0][i]==t[0][l+j]) j++;
//		if(j==M){
//			// check hash same
////			if(check(0,i-ft[bel[i]]+1+1,))
//			debug(al[0],i,ed[bl[i]],bl[i]);
//			auto ss=al[0].substr(i+1,ed[bl[i]]-i-1);
//			auto tt=t[0].substr(r+1,t[0].size()-r);
//			debug(ss,tt);
//			if(ss==tt)
//				vis[i]=1,p.push_back(i);
//		}
//	}
//	for(int i=2,j=0; i<=M; i++){
//		while(j&&t[1][l+i]!=t[1][l+j+1]) j=nxt[j];
//		if(t[1][l+i]==t[1][l+j+1]) j++;
//		nxt[i]=j;
//	}
//	for(int i=1,j=0; i<=nn; i++){
//		while(j&&al[1][i]!=t[1][l+j+1]) j=nxt[j];
//		if(al[1][i]==t[1][l+j+1]) j++;
//		if(j==M&&vis[i]){
//			
//			auto ss=al[0].substr(i+1,ed[bl[i]]-i);
//			auto tt=t[0].substr(r+1,t[0].size()-r);
//			if(ss==tt)
//				res++;
//		}
//	}
//	for(int x:p) vis[x]=0;
//	return res;
///*
	
	int M=r-l+1;int res=0;
	auto T=t[0].substr(l,M),TT=t[1].substr(l,M);
//	debug(T);
	for(int j=1; j<=n; j++){
		for(int k=0; k<=L[j]; k++){
			if(k+M-1>=L[j]) break;
//			debug(j,k);
			string S=s[0][j].substr(k,M);
//			debug(S,T,SS,TT);
			if(S==T){
				string SS=s[1][j].substr(k,M);
				if(TT==SS) res++;
			}
		}
	}
	return res;
//*/

}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>n>>q;
	al[0]=al[1]="#";
	for(int i=1; i<=n; i++){
		cin>>s[0][i]>>s[1][i];
		int v=al[0].size();
		L[i]=s[0][i].size();
		s[0][i]+='#',s[1][i]+='#';
		al[0]+=s[0][i],al[1]+=s[1][i];
		ed[i]=al[0].size()-1;
		for(int j=v; j<=ed[i]; j++) bl[j]=i;
			
	}
	nn=al[0].size();
	for(int i=1; i<=q; i++){
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<"0\n";
			continue;
		}
//		int res=0;
		int l=0,r=t[0].size();
		while(l<r&&t[0][l]==t[1][l]) l++; 
		while(r>0&&t[0][r]==t[1][r]) r--;
//		debug(l,r);
		cout<<solve(l,r)<<'\n';
		 
	
	}
	return 0;
}
/*
2 1
xabcx xadex
bc de
xabcx xadex


3 4
a b
b c
c d
a c
b a

3 1
a b
b c
c d
aa bb
*/

