#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
int n,k1,k2,k3;
int a[N][3];
int s1[N],s2[N],s3[N];
struct data{
	int a,b,c,i;
	int best;
}dp[N];
bool cmp(int a,int b){
	if(dp[a].best==1){
		return dp[a].a>dp[b].a;
	}
	if(dp[a].best==2){
		return dp[a].b>dp[b].b;
	}
	if(dp[a].best==3){
		return dp[a].c>dp[b].c;
	} 
}
int main( ){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int x=0;x<t;x++){
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			dp[i].a=a[i][0];
			dp[i].b=a[i][1];
			dp[i].c=a[i][2];
			dp[i].i=i;
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]) {
				dp[i].best=1;
				s1[++k1]=i;
			}
			else if(a[i][1]>a[i][0]&&a[i][1]>a[i][2]) {
				dp[i].best=2;
				s2[++k2]=i;
			}
			else {
				dp[i].best=3;
				s3[++k3]=i;
			}
		}
	    sort(s1+1,s1+1+k1,cmp);
	    if(k1>n/2){
	    	for(int i=k1;i>=n/2+1;i--){
	    		if(dp[s1[i]].b>dp[s1[i]].c){
	    			dp[s1[i]].best=2;
	    			s2[++k2]=s1[i];
				}
				else{
					dp[s1[i]].best=3;
	    			s3[++k3]=s1[i];
				}
				--k1;
			}
		}
	    sort(s2+1,s2+1+k2,cmp);
	    if(k2>n/2){
	    	for(int i=k2;i>=n/2+1;i--){
				if(dp[s2[i]].a>dp[s2[i]].c){
	    			dp[s2[i]].best=1;
	    			s1[++k1]=s2[i];
				}
				else{
					dp[s2[i]].best=3;
	    			s3[++k3]=s1[i];
				}
				--k2;
			}
		}
	    sort(s3+1,s3+1+k3,cmp);
	    if(k2>n/2){
	    	for(int i=k3;i>=n/2+1;i--){
				if(dp[s3[i]].a>dp[s3[i]].b){
	    			dp[s3[i]].best=1;
	    			s1[++k1]=dp[s3[i]].i;
				}
				else{
					dp[s3[i]].best=2;
	    			s2[++k2]=dp[s3[i]].i;
				}
				--k3;
			}
		}
		for(int i=1;i<=k1;i++){
			ans+=dp[s1[i]].a;
//			cout<<dp[s1[i]].a<<" ";
		}
		for(int i=1;i<=k2;i++){
			ans+=dp[s2[i]].b;
//			cout<<dp[s2[i]].b<<" ";
		}
		for(int i=1;i<=k3;i++){
			ans+=dp[s3[i]].c;
//			cout<<dp[s3[i]].c<<" ";
		}
		cout<<ans<<endl;
	}
	return 0;
}

