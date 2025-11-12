#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+1;
int a[N],b[N],c[N];
struct node{
	int a,b,c;
}f[N],dp[2*N];
int fl[2*N];
int cmp(node x,node y){
	return x.a<y.a;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		int res=0,ans=0,sum=0;
		cin>>n;
		memset(fl,0,sizeof(fl));
		int x=n/2,vis=0,y=0;
		for(int i=1;i<=n;i++){
			cin>>f[i].a>>f[i].b>>f[i].c;
			int maxn=max(f[i].a,max(f[i].b,f[i].c));
			if(maxn==f[i].a){
				a[++res]=f[i].a;
				vis+=f[i].a;
				dp[++y].a=f[i].b-f[i].a;
				dp[y].b=i;
				dp[y].c=1;
				dp[++y].a=f[i].c-f[i].a;
				dp[y].b=i;
				dp[y].c=1;
			}else if(maxn==f[i].b){
				b[++sum]=f[i].b;
				vis+=f[i].b;
				dp[++y].a=f[i].a-f[i].b;
				dp[y].b=i;
				dp[y].c=2;
				dp[++y].a=f[i].c-f[i].b;
				dp[y].b=i;
				dp[y].c=2;
			}else{
				c[++ans]=f[i].c;
				vis+=f[i].c;
				dp[++y].a=f[i].a-f[i].c;
				dp[y].b=i;
				dp[y].c=3;
				dp[++y].a=f[i].b-f[i].c;
				dp[y].b=i;
				dp[y].c=3;
			}
		}
		sort(dp+1,dp+1+2*n,cmp);
		if(res>x){
			for(int i=2*n;i>=1;i--){
				if(res<=x) break;
				if(!fl[dp[i].b]){
					fl[dp[i].b]=1;
					if(dp[i].c==1){
						vis+=dp[i].a;
						res--;
					}
				}
			}
		}else if(sum>x){
			for(int i=2*n;i>=1;i--){
				if(sum<=x) break;
				if(!fl[dp[i].b]){
					fl[dp[i].b]=1;
					if(dp[i].c==2){
						vis+=dp[i].a;
						sum--;
					}
				}
			}
		}else if(ans>x){
			for(int i=2*n;i>=1;i--){
				if(ans<=x) break;
				if(!fl[dp[i].b]){
					fl[dp[i].b]=1;
					if(dp[i].c==3){
						vis+=dp[i].a;
						ans--;
					}
				}
			}
		}
		cout<<vis<<endl;
	}
	return 0;
}//Ren5Jie4Di4Ling5%
