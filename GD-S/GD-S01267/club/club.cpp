#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int M=1e5+5;
int dp[N][N],n,T;
struct node{
	int a,b,c;
}a[M];
bool cmp1(node a,node b){
	return a.a-a.b>b.a-b.b;
}
bool cmp2(node a,node b){
	return a.c-a.a>b.c-b.a;
}
bool cmp3(node a,node b){
	return a.c-a.b>b.c-b.b;
}
int solve2(){
	sort(a+1,a+n+1,cmp1);
	int ans=0,i=0,j=0,now=0,k;
	for(i=1;i<=n/2;i++) now+=a[i].a;
	for(j=n/2+1;j<=n;j++) now+=a[j].b;
	i=1;j=n/2+1;ans=now;
	sort(a+1,a+n/2+1,cmp2);
	sort(a+n/2+1,a+n+1,cmp3);
	for(k=1;k<=n/2;k++){
		if(j>n||i>n/2) break;
		if(a[i].c-a[i].a>a[j].c-a[j].b){
			now+=a[i].c-a[i].a;
			i++;
		}else{
			now+=a[j].c-a[j].b;
			j++;
		}
		ans=max(ans,now);
	}
	while(k<=n/2&&i<=n/2){
		now+=a[i].c-a[i].a;
		ans=max(ans,now);
		i++;k++;
	}
	while(k<=n/2&&j<=n){
		now+=a[j].c-a[j].b;
		ans=max(ans,now);
		j++;k++;
	}
	return ans;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].a>>a[i].b>>a[i].c;
		if(n>=450){
			cout<<solve2()<<'\n';
			continue;
		}
		memset(dp,128,sizeof(dp));
		dp[0][0]=0;
		int ans=-2e9;
		for(int i=1;i<=n;i++){
			for(int t=n/2;t>=0;t--){
				for(int k=n/2;k>=0;k--){
					if(i-t-k<=n/2&&k+t<=i){
						dp[t][k]=dp[t][k]+a[i].c;
						if(t) dp[t][k]=max(dp[t-1][k]+a[i].a,dp[t][k]);
						if(k) dp[t][k]=max(dp[t][k],dp[t][k-1]+a[i].b);
						if(i==n) ans=max(ans,dp[t][k]);
					}else dp[t][k]=-2e9;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}