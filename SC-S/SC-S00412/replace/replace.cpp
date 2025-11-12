#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1; char c=0;
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return x*f;
}
int n,q;
const int N=2e5+10,base=116315,mod=998244353;
string s[N][2];
vector<int> h[N][2];
int P[N];
inline int get(int id,int type,int l,int r){
	if(!l) return h[id][type][r];
	return ((h[id][type][r]-1ll*h[id][type][l-1]*P[r-l]%mod)%mod+mod)%mod;
}
string t[2];
int th[2][N];
inline int gett(int id,int l,int r){
	if(!l) return th[id][r];
	return ((th[id][r]-1ll*th[id][l-1]*P[r-l]%mod)%mod+mod)%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	P[0]=1;
	for(int i=1;i<N;i++)
		P[i]=1ll*P[i-1]*base%mod;
	for(int i=1;i<=n;i++){
		cin>>s[i][0];
		int m=s[i][0].length();
		h[i][0].push_back(s[i][0][0]);
		for(int j=1;j<m;j++){
			h[i][0].push_back((1ll*h[i][0].back()*base+s[i][0][j])%mod);
		}
		cin>>s[i][1];
		h[i][1].push_back(s[i][1][0]);
		for(int j=1;j<m;j++){
			h[i][1].push_back((1ll*h[i][1].back()*base+s[i][1][j])%mod);
		}
	}
//	cerr<<"hsh : "<<get(3,0,0,1)<<" "<<get(3,1,0,1)<<"\n";
	while(q--){
		int ans=0;
		cin>>t[0];	
		int len=t[0].length();
		th[0][0]=t[0][0];
		for(int j=1;j<len;j++){
			th[0][j]=(1ll*th[0][j-1]*base%mod+t[0][j])%mod;
//			cerr<<"th : "<<j<<" "<<th[0][j]<<"\n";
		}
		cin>>t[1];
		th[1][0]=t[1][0];
		for(int j=1;j<len;j++){
			th[1][j]=(1ll*th[1][j-1]*base%mod+t[1][j])%mod;
		}
		int l=0,r=len-1;
		for(int i=l;i<=r;i++){
			if(t[0][i]==t[1][i]) l=i+1;
			else break;
		}
		for(int i=r;i>=l;i--){
			if(t[0][i]==t[1][i]) r=i-1;
			else break;
		}
		int hsh[2]={gett(0,l,r),gett(1,l,r)};
//		cerr<<"l r : "<<l<<" "<<r<<"\n";
//		cerr<<"hsh : "<<hsh[0]<<" "<<hsh[1]<<"\n";
//		cerr<<"hsh2 : "<<gett(0,r,r)<<" "<<gett(1,r,r)<<"\n";
		for(int i=1;i<=n;i++){
			int m=s[i][0].length();
			for(int j=(r-l);j<m;j++){
				bool flag=true;
				for(int k=j-(r-l);k<=j;k++){
					if(s[i][0][k]!=t[0][k-(j-(r-l))+l]){
						flag=false;
						break;
					}
				}
				if(flag){
					for(int k=j-(r-l);k<=j;k++){
						if(s[i][1][k]!=t[1][k-(j-(r-l))+l]){
							flag=false;
							break;
						}
					}
					if(flag){
						int plen=j-(r-l);
						if(plen<=l && l-plen+m-1<len){
							for(int k=0;k<m;k++){
								if(s[i][0][k]!=t[0][l-plen+k]){
									flag=false;
									break;
								}
							}
							if(flag){
								for(int k=0;k<m;k++){
									if(s[i][1][k]!=t[1][l-plen+k]){
										flag=false;
										break;
									}
								}
								ans+=flag;
							}
						}
					}
				}
//				if(get(i,0,j-(r-l),j)==hsh[0]){
//					if(get(i,1,j-(r-l),j)==hsh[1]){
//						int plen=j-(r-l);
//						 && get(i,0,0,m-1)==gett(0,,l-plen+m-1) 
//						&& get(i,1,0,m-1)==gett(1,l-plen,l-plen+m-1)) ans++;
//					}
//				}
			}
//			cerr<<"now ans : "<<i<<" "<<ans<<"\n";
		}
		printf("%d\n",ans);
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
*/