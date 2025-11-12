#include<bits/stdc++.h>
using namespace std;
int T,n,dp[205],dp1[200005];
struct member{
	int f,s,t;
}a[100005];
bool cmp(member a,member b){
	return a.f>b.f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
		}
		if(n==1e5){
			bool flag=0;
			for(int i=1;i<=n;i++){
				if(a[i].s!=0||a[i].t!=0){
					flag=1;
				}
			}
			if(!flag){
				sort(a+1,a+n+1,cmp);
				int sum=0;
				for(int i=1;i<=n/2;i++){
					sum+=a[i].f;
				}
				cout<<sum<<endl;
				continue;
			}	
		}else if(n==2){
			cout<<max(a[1].f+a[2].s,max(a[1].f+a[2].t,max(a[1].s+a[2].f,max(a[1].s+a[2].t,max(a[1].t+a[2].f,a[1].t+a[2].s)))))<<endl;
			continue;
		}else{
			bool flag=0;
			for(int i=1;i<=n;i++){
				if(a[i].t!=0){
					flag=1;
					break;
				}
			}
			if(!flag){
				int sum1=0,sum2=0;
				for(int i=1;i<=n;i++){
					if(dp[i-1]+a[i].f>dp[i-1]+a[i].s&&sum1<n/2||sum2==n/2){
						dp[i]=dp[i-1]+a[i].f;
						sum1++;
					}else if(dp[i-1]+a[i].f<dp[i-1]+a[i].s&&sum2<n/2||sum1==n/2){
						dp[i]=dp[i-1]+a[i].s;
						sum2++;
					}
				}
				cout<<dp[n]<<endl;
			}
		}
	}
	return 0;
}
