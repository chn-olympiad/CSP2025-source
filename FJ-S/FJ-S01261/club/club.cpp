#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,t,sum;
int a[maxn][3]={0},maxh[maxn]={0},minh[maxn]={0};
int num[maxn]={0};
long long ans=0,dp[maxn][4];
float find(int x,int y,int m,int h){
	if(h==x) return 0;
	if(h==y) return 1;
	if(h==m) return 2;
} 
int max1(int a,int b,int c){
	if(a>b&&a>c) return a;
	if(b>a&&b>c) return b;
	return c;

}/*
void anss(int t1,int t2,int t3,int i ){
	if(i==0) {
	    dp[0][1]=a[0][0];
		dp[0][2]=a[0][1];
		dp[0][3]=a[0][2];
	}
	else if(t1==1){
	anss(t1,t2--,t3,i--);
	anss(t1,t2,t3--,i--);
	dp[i][1]=0;
    dp[i][2]=max1(dp[i-1][1]+a[i][1],dp[i-1][2]+a[i][1],dp[i-1][3]+a[i][1]);
    dp[i][3]=max1(dp[i-1][1]+a[i][2],dp[i-1][2]+a[i][2],dp[i-1][3]+a[i][2]);
    	
	} 
	else if(t2==1){
	anss(t1--,t2,t3,i--);
	anss(t1,t2,t3--,i--);
	dp[i][1]=max1(dp[i-1][1]+a[i][0],dp[i-1][2]+a[i][0],dp[i-1][3]+a[i][0]);
    dp[i][2]=0;
    dp[i][3]=max1(dp[i-1][1]+a[i][2],dp[i-1][2]+a[i][2],dp[i-1][3]+a[i][2]);
}
	else if(t3==1) {
	anss(t1,t2--,t3,i--);
	anss(t1--,t2,t3,i--);
	dp[i][1]=max1(dp[i-1][1]+a[i][0],dp[i-1][2]+a[i][0],dp[i-1][3]+a[i][0]);
    	dp[i][2]=max1(dp[i-1][1]+a[i][1],dp[i-1][2]+a[i][1],dp[i-1][3]+a[i][1]);
    	dp[i][3]=0;
	}
	else {
	    anss(t1,t2--,t3,i--);
		anss(t1--,t2,t3,i--);
		anss(t1,t2,t3--,i--);
		dp[i][1]=max1(dp[i-1][1]+a[i][0],dp[i-1][2]+a[i][0],dp[i-1][3]+a[i][0]);
    	dp[i][2]=max1(dp[i-1][1]+a[i][1],dp[i-1][2]+a[i][1],dp[i-1][3]+a[i][1]);
    	dp[i][3]=max1(dp[i-1][1]+a[i][2],dp[i-1][2]+a[i][2],dp[i-1][3]+a[i][2]);
    	
	}
		
	
}*/
bool cmp1(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int u=0;u<t;++u){
    	ans=0;
    	scanf("%d",&n);
    	int sum1[3]={0};
    	for(int i=0;i<n;++i){
    		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
    		maxh[i]=max1(a[i][0],a[i][1],a[i][2]) ;
    		minh[i]=min(a[i][0],a[i][1]);
    //		sum1[num[i]]++;
		}
		if(a[0][2]==0&&a[0][3]==0){
		sort(maxh,maxh+n,cmp1);
		for(int i=0;i<n/2;++i)
		ans+=maxh[i];
//	 anss(n/2,n/2,n/2,n-1);
		/*
		dp[0][1]=a[0][0];
		dp[0][2]=a[0][1];
		dp[0][3]=a[0][2];
    	for(int i=1;i<n;++i){
    		dp[i][1]=max1(dp[i-1][1]+a[i][0],dp[i-1][2]+a[i][0],dp[i-1][3]+a[i][0]);
    		dp[i][2]=max1(dp[i-1][1]+a[i][1],dp[i-1][2]+a[i][1],dp[i-1][3]+a[i][1]);
    		dp[i][3]=;
    		
		}*/
    	printf("%lld\n",ans);
    //	printf("%lld\n",max1(dp[n-1][1],dp[n-1][2],dp[n-1][3]));	
		}
		else {
		ans=0;
		for(int j=0;j<n;++j)
			for(int i=1;i<n;++i){
			
				if(maxh[i]<maxh[i-1]){
				swap(maxh[i],maxh[i-1]);
				swap(minh[i],minh[i-1]);
			}
			}
			for(int i=0;i<n/2;++i)
			ans+=maxh[i];
			for(int i=n/2;i<n;++i)
			ans+=minh[i];
				printf("%lld\n",ans);
		
		}
	}
    



	return 0;
} 





/*
我是新人
5bts，再见
*/ 




















