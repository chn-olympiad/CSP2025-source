#include<bits/stdc++.h>
using namespace std;

#define LL long long

void read(LL &x){
	scanf("%lld",&x);
}

void write(LL x){
	printf("%lld\n",x);
}

void write(LL x,LL op){
	if(!op) printf("%lld ",x);
	else printf("%lld\n",x);
}

const LL N=2e5+10,M=5e6+10,p=13331,mod=1e9+7;

LL n,q,len[N];

string s[2],t[2];

LL sum[N][2];

LL sumt[M][2],pre[M];

LL calct(LL l,LL r,LL op){
	return ((sumt[r][op]-sumt[l-1][op]*pre[r-l+1])%mod+mod)%mod;
} 

void solve(){
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(LL i=1;i<=n;i++){
		cin>>s[0]>>s[1];
		len[i]=s[0].length();
		for(LL j=0;j<2;j++){
			for(LL k=0;k<len[i];k++){
				sum[i][j]=(sum[i][j]*p+s[j][k])%mod;
			}
		}
	}
	pre[0]=1;
	for(LL i=1;i<M;i++) pre[i]=pre[i-1]*p%mod;
	while(q--){
		cin>>t[0]>>t[1];
		LL len0=t[0].length(),len1=t[1].length();
		if(len0!=len1){
			printf("0\n");
			continue;
		}
		for(LL i=1;i<=len0;i++) for(LL j=0;j<2;j++) sumt[i][j]=(sumt[i-1][j]*p+t[j][i-1])%mod;
		LL k=-1;
		for(LL i=1;i<=len0;i++){
			if(t[0][i-1]!=t[1][i-1]){
				k=i;
				break;
			}
		}
		LL ans=0;
		for(LL i=1;i<=n;i++){
			LL l=max((LL)1,k-len[i]+1),r=min(len0-len[i]+1,k);
			bool bl=false;
			for(LL j=l;j<=r;j++){
				if(calct(j,j+len[i]-1,0)==sum[i][0]){
					if(((sumt[len0][0]-(sum[i][0]-sum[i][1])%mod*pre[len0-(j+len[i]-1)])%mod+mod)%mod==sumt[len0][1]){
						bl=true;
						break;
					}
				}
			}
			ans+=bl;
		}
		write(ans);
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	LL T=1;
//	read(T);
	while(T--){
		solve();
	}
	return 0;
}

