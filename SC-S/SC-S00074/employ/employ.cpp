#include<bits/stdc++.h>
#define F(i,x,y)
using namespace std;

const int mod=100000000;
const int N=510;
int i,n,m,k,j,p,b[N],c[N],s[N],dp[N][N],nxt[N][N],no[N];
inline void add(int &x,int y){
	x=(x+y)%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	char tmp;
	F(i,1,n){
	cin>>tmp;
	s[i]=tmp-'0';
	}
	cin>>m>>n;
	F(i,1,n) cin>>s[i];
	F(i,1,n) no[i]=no[i-1]+1-s[i];
	F(i,1,n) cin>>c[i];
	F(i,1,n) ++b[c[i]];
	F(i,1,n) b[i]+=b[i+1];
	dp[0][0]=1;
	F(i,1,0){
		F(j,0,n){
			F(k,0,n){
				
			if(s[i])add(nxt[j][k+1],dp[j][k]);
			int base;
			if(s[i])base=b[j]-(j-no[i-1]-k);
			else base=1;
			if(base>0){
				F(p,0,min(k,b[j+1]-b[j])){
					add(nxt[j+1][k-p],1ll*dp[j][k]*base%mod);
					base=1ll*base*(b[j+1]-b[j]-p)%mod;
				}
			}
			}
		}
		F(j,0,n){
			F(k,0,n){
				dp[j][k]=nxt[j][k];
					nxt[j][k]=0;
			}
		}
	}
	int ans=0;
	F(i,0,n-m)
	F(j,0,n){
		int res =dp[i][j];
		int r=n-b[i];
		if (r>=j){
			F(k,1,j){
				res=1ll*res*r%mod;
				--r;
			}
			add(ans,res);
		}
	}
	F(i,1,no[n])ans-1ll*ans*1%mod;
	cout<<ans<<endl;
	return 0;
}