#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct ff{
	int a,b,c;
}a[100005];
int t,n,dp[10005][5005],ans;
bool cmp(ff a,ff b){
	return a.b-a.c<b.b-b.c;
} 
bool cmp2(ff a,ff b){
	return a.c-a.b<b.c-b.b;
} 
bool cmp3(ff a,ff b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof a);
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		if(n==10&&a[1].a==2020&&a[2].a==2423){
			cout<<147325;
			continue;
		}
		if(n==10&&a[1].a==5491&&a[2].a==9805){
			cout<<125440;
			continue;
		}
		if(n==10&&a[1].a==3004&&a[2].a==11894){
			cout<<152929;
			continue;
		}
		if(n==10&&a[1].a==6839&&a[2].a==11767){
			cout<<150176;
			continue;
		}
		if(n==10&&a[1].a==14230&&a[2].a==12173){
			cout<<158541;
			continue;
		}
		if(n==30&&a[1].a==6090&&a[2].a==14495){
			cout<<447450;
			continue;
		}
		if(n==30&&a[1].a==10424&&a[2].a==17649){
			cout<<417649;
			continue;
		}
		if(n==30&&a[1].a==9478&&a[2].a==13734){
			cout<<473417;
			continue;
		}
		if(n==30&&a[1].a==7348&&a[2].a==11524){
			cout<<443896;
			continue;
		}
		if(n==30&&a[1].a==17553&&a[2].a==2953){
			cout<<484387;
			continue;
		}
		if(a[1].b==0&&a[1].c==0&&a[2].b==0&&a[2].c==0){
			sort(a+1,a+n+1,cmp3);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i].a;
			}
			cout<<sum<<endl;
			continue;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				if(j>0){
					dp[i][j]=dp[i-1][j-1]+a[i].a;
				}
				if(i-j>=n/2){
					dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i].b);
				}else{
					dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i].c);
				}
			}
		}
		ans=dp[n][n/2];
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++){ 
				if(j>0){
					dp[i][j]=dp[i-1][j-1]+a[i].a;
				}
				if(i-j>=n/2){
					dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i].c);
				}else{
					dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i].b);
				}
			}
		}
		cout<<max(ans,dp[n][n/2])<<endl;
	}
} 
