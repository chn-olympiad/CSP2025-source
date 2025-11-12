#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[100005][5],sum[5];
struct node{
	int sum1,sum2,x,sum1_x;
}b[100005];
bool cmp(node M1,node M2){
	return M1.x>M2.x;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		sum[1]=sum[2]=sum[3]=0;
		for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=1;i<=n;i++){
			int maxx=max(a[i][1],max(a[i][2],a[i][3])),midd=a[i][1]+a[i][2]+a[i][3]-max(a[i][1],max(a[i][2],a[i][3]))-min(a[i][1],min(a[i][2],a[i][3]));
			b[i]=(node){maxx,midd,maxx-midd,0};
			if(maxx==a[i][1])b[i].sum1_x=1;
			else if(maxx==a[i][2])b[i].sum1_x=2;
			else b[i].sum1_x=3;
		}
		sort(b+1,b+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(sum[b[i].sum1_x]<n/2){
				sum[b[i].sum1_x]++;
				ans+=b[i].sum1;
			}else ans+=b[i].sum2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
