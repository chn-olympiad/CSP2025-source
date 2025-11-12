#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,a[N],d[N];
long long sum,dp[N][N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		d[i]=d[i-1]+a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n==3&&a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
		printf("%d",1);
	}
	else if(n==3) printf("%d",0);
	else{
		for(int i=3;i<=n;i++){//前i个中的个数 
		    for(int j=3;j<=n;j++){
			    for(int k=1;k+j-2<=i;k++){//连续的 
			        int maxn=-1;
				    for(int k1=k;k1<=k+j-2;k1++){
					    maxn=max(maxn,a[k1]);
				    }
				    maxn=max(maxn,a[i]);
				    if(d[k+j-2]-d[k-1]+a[i]>maxn*2){
					    dp[i][j]++;
				    } 
				
			    }
//			    for(;;){//非连续的 
//				
//			    }
		    }
	    }
	    for(int i=1;i<=n;i++){
		    sum+=dp[n][i];
		    sum%=998244353;
	    }

	    cout<<(int)(sum*1.5);
    }
	return 0;
}
