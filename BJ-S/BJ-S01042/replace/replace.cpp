#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define pi pair<int,int>
#define arr(a) array<int,(a)>
#define cases(_) while((_)--) solve()
#define RE return puts("0"),void();
using namespace std;
const int N=5000005,BASE=37;
const ll mod=33333333333333337;
int _=1,n,q,cnt,lenl[N],lenr[N],M[N],sr[N];
vector<ll> hsh1[N],hsh2;
ll t1[N],t2[N];
char c1[N],c2[N];
inline ll gethash1(int o,int l,int r){
	return (hsh1[o][r]-hsh1[o][l-1]*M[r-l+1]%mod+mod)%mod;
}
inline ll gethash2(int l,int r){
	return (hsh2[r]-hsh2[l-1]*M[r-l+1]%mod+mod)%mod;
}
void solve(){
	scanf("%d%d",&n,&q);
	rep(i,1,n){
		scanf("%s%s",c1+1,c2+1);
		int m=strlen(c1+1),l=0,r=0;
		hsh1[i].assign(m+1,0);
		rep(o,1,m) if(c1[o]!=c2[o]){l=o;break;}
		_rep(o,m,1) if(c1[o]!=c2[o]){r=o;break;}
		rep(o,1,m) hsh1[i][o]=(hsh1[i][o-1]*BASE+(c1[o]-'a'+1))%mod;
		if(!l && !r) lenl[i]=lenr[i]=m;
		else{
			lenl[i]=l-1,lenr[i]=m-r,sr[i]=r;
			_rep(o,r,l){
				t1[i]=(t1[i]*BASE+(c1[o]-'a'+1))%mod,t2[i]=(t2[i]*BASE+(c2[o]-'a'+1))%mod;
			}
		}
	}
	rep(i,1,q){
		scanf("%s%s",c1+1,c2+1);
		int m=strlen(c1+1),l=0,r=0;
		hsh2.assign(m+1,0);
		if(m!=(int)strlen(c2+1)){
			puts("0");
			continue;
		}
		rep(i,1,m) if(c1[i]!=c2[i]){l=i;break;}
		_rep(i,m,1) if(c1[i]!=c2[i]){r=i;break;}
		ll tt1=0,tt2=0;int ans=0;
		_rep(i,r,l) tt1=(tt1*BASE+(c1[i]-'a'+1))%mod,tt2=(tt2*BASE+(c2[i]-'a'+1))%mod;
		rep(o,1,m) hsh2[o]=(hsh2[o-1]*BASE+(c1[o]-'a'+1))%mod;
		if(!l && !r) rep(j,1,n){if(!t1[j] && !t2[j] && hsh2[lenl[j]]==hsh1[j][lenl[j]]) ans++;}
		else{
			rep(j,1,n) if(tt1==t1[j] && tt2==t2[j]){
				if(lenl[j]>=l || lenr[j]>=m-r+1) continue;
				int tl=lenl[j],tr=lenr[j];
				if(tl==0 || gethash2(l-tl,l-1)==gethash1(j,1,tl)){
					if(tr==0 || gethash2(r+1,r+tr)==gethash1(j,sr[j]+1,sr[j]+tr)) ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	// scanf("%d",&_);
	M[0]=1;
	rep(i,1,N-1) M[i]=M[i-1]*BASE%mod;
	cases(_);
	return 0;
}
