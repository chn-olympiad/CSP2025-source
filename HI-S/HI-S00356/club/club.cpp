#include<bits/stdc++.h>
#define cint const int
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=1e5+5;
int t;
int n;
ll ans;
ll f[205][105][105];
struct node{
	ll a,b,c;
}num[N];
bool cmp(node a,node b){
	return a.a>b.a;
}
int main()
{
 	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		memset(f,0,sizeof(f));
		bool fl=0;
		for(int j=1; j<=n; j++){
			scanf("%lld%lld%lld",&num[j].a,&num[j].b,&num[j].c);
			if(num[j].b!=0 || num[j].c!=0) fl=1;
		}
		if(!fl){
			sort(num+1,num+n+1,cmp);
			for(int j=1; j<=n/2; j++){
				ans+=num[j].a;
			}
			printf("%lld\n",ans);
			continue;
		}
		for(int j=1; j<=n; j++){
			for(int k=0; k<=min(n/2,j); k++){
				for(int l=0; l<=min(n/2,j-k); l++){
					if(k>0) f[j][k][l]=max(f[j-1][k-1][l]+num[j].a,f[j][k][l]);
					if(l>0) f[j][k][l]=max(f[j-1][k][l-1]+num[j].b,f[j][k][l]);
					if(k+l<=min(j-1,n/2) && j-k-l<=n/2){
						f[j][k][l]=max(f[j][k][l],f[j-1][k][l]+num[j].c);
					}
					ans=max(ans,f[j][k][l]);
					//cout<<j<<" "<<k<<' '<<l<<' '<<f[j][k][l]<<endl;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

