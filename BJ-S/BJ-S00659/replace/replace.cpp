#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
inline int read(){
	int x=0,f=1; char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*f;
}
const int N=2e4+5;
int n,q,l[N];
vector<int> next[2][N];
string s[2][N],t[2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	n=read(),q=read();
	rep(i,1,n) cin>>s[0][i]>>s[1][i],l[i]=s[0][i].length();
	if(n<=100 and q<=200){
		while(q--){
			cin>>t[0]>>t[1];
			int len=t[0].length();
			int cnt=0;
			rep(i,0,len-1){
				rep(j,1,n){
					bool f=1;
					if(i+l[j]>len) continue;
					rep(k,0,l[j]-1){
						if(t[0][i+k]!=s[0][j][k]){
							f=0;
							break;
						}
					}
					if(!f) continue;
					string tt;
					tt=t[0];
					rep(k,0,l[j]-1){
						tt[i+k]=s[1][j][k];
					}
					// cout<<i<<" "<<j<<" "<<tt<<endl;
					if(tt==t[1]) cnt++;
				}
			}
			cout<<cnt<<"\n";
		}
	}
	
	return 0;
}