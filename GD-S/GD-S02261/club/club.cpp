#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define int long long
struct NOIP{
	int a,b,c;
}x[N];
bool cmp(NOIP i,NOIP j){
	return (i.a-i.b)>(j.a-j.b);
}
int f[205][105][105];
int dk[N];
int n,m,j,k,l,ans,t;
int cc;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	scanf("%lld",&t);
	while(t--){
		ans=0;
		memset(f,0,sizeof f);
		cc=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&x[i].a,&x[i].b,&x[i].c);
			if(x[i].c!=0)cc=1;
		}
		sort(x+1,x+1+n,cmp);
		if(cc==0){
			for(int i=1;i<=n;i++){
				if(i<=n/2)ans+=x[i].a;
				else ans+=x[i].b;
			}
			printf("%lld\n",ans);
			continue;
		}
		if(n<=200){
			int maxi=0;
			for(int i=1;i<=n;i++){
				for(j=0;j<=n/2;j++){
					if(j>i)break;
					for(k=0;k<=n/2;k++){
						if(k+j>i)break;
						if(i-k-j>n/2)continue;
						if(j!=0)f[i][j][k]=f[i-1][j-1][k]+x[i].a;
						if(k!=0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+x[i].b);
						if(i-k-j!=0)f[i][j][k]=max(f[i-1][j][k]+x[i].c,f[i][j][k]);
						maxi=max(maxi,f[i][j][k]);
					}
				}
			}	
			printf("%lld\n",maxi);
			continue;
		}
		for(int i=1;i<=n;i++){
			ans+=max(x[i].a,max(x[i].b,x[i].c));
		}
		printf("%lld\n",ans);
	}
	
	return 0;
 } 
