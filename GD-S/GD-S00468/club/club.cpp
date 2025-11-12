#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,t,dp[100010][10],ans,flag,aa,bb,cc; 
struct m{
	ll a,b,c,bm;
}w[100010];
bool cmp(m a,m b){
	return a.a<b.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		memset(w,0,sizeof(w));
		aa=(n/2);
		bb=aa;
		cc=bb;
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&w[i].a,&w[i].b,&w[i].c);
		}
		for(int i=1;i<=n;i++){
			if(w[i].b){
				if(w[i].c){
					flag=1;
					break;
				}
			}
		}
		if(flag==0){			
			sort(w+1,w+1+n,cmp);
			for(int i=1;i<=(n/2);i++){
				dp[3][n]+=w[i].a;
			}
		}/*
		for(int i=1;i<=n;i++){
			for(int j=n/2;j>=i;j--){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+w[i].a);
			}
		}
		*/
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n/2;j++){
				if(i==1){
					if(aa){
						dp[i][j]=max(dp[i][j],dp[i][j-1]+w[j].a);
//						w[j].a=0;
						aa--;
					}
				}
				if(i==2){
					if(bb){
						dp[i][j]=max(dp[i][j],dp[i][j-1]+w[j].b);
//						w[j].b=0;
						bb--;
					}
				}
				if(i==3){
					if(bb){
						dp[i][j]=max(dp[i][j],dp[i][j-1]+w[j].c);
//						w[j].c=0;
						cc--;
					}
				}
			}
		}
		printf("%lld\n",dp[3][n/2]);
	}
	return 0;
}

