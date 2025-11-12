 #include<bits/stdc++.h>
 using namespace std;
 #define int long long
 const int N=210,M=1e5+10;
 int T,n;
 int lst[N][3];
 int dp[N][N];
 int arr[M][3]; 
 int arr2[M];
 int f[M];
 signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		if(n<=200){
			for(int i=0;i<N;i++)for(int j=0;j<N;j++)dp[i][j]=0;
			for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&lst[i][0],&lst[i][1],&lst[i][2]);
			for(int i=1;i<=n;i++){
				for(int j=min(i,n/2);j>=0;j--){
					for(int k=min(i-j,n/2);k>=0&&i-j-k<=n/2;k--){
						int a,b,c;
						if(j>=1)a=dp[j-1][k]+lst[i][0];
						else a=-1;
						if(k>=1)b=dp[j][k-1]+lst[i][1];
						else b=-1;
						if(i-j-k>=1)c=dp[j][k]+lst[i][2];
						else c=-1;
						dp[j][k]=max({a,b,c});
					}
				}
			}
			int maxx=0;
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)maxx=max(maxx,dp[i][j]);
			printf("%lld\n",maxx);
		}else{
			bool b=0,c=0;
			for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&arr[i][0],&arr[i][1],&arr[i][2]),b|=arr[i][1],c|=arr[i][2];
			if(!(b||c)){
				int ans=0;
				for(int i=1;i<=n;i++)arr2[i]=arr[i][0];
				sort(arr2+1,arr2+1+n);
				for(int i=1;i<=n/2;i++)ans+=arr2[i];
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
 }
