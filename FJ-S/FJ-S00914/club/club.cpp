#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][4];
void work(){
	int b[100005];
	for(int i=1;i<=n;i++){
		b[i]=a[i][1];
	}
	sort(b,b+n+1);
	long long ans=0;
	for(int i=n;i>n/2;i--){
		ans+=b[i];
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	//cout<<t<<endl;
	for(int p=1;p<=t;p++){
		int ans=0;
		int dp[203][103][103][103];
		cin>>n;
		//cout<<n<<endl;
		bool flag=1;
		for(int i=1;i<=n;i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) flag=0;
			//cout<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<endl;
		}
		if(flag){
			work();
			continue;
		}
		int mid=n/2;
		for(int x1=0;x1<=mid;x1++)
			for(int x2=0;x2<=mid;x2++)
				for(int x3=0;x3<=mid;x3++)
					dp[0][x1][x2][x3]=0;
		for(int i=1;i<=n;i++){
			dp[i][0][0][0]=0;
			dp[i][0][0][1]=max(a[i][3],dp[i-1][0][0][1]);
			dp[i][0][1][0]=max(a[i][2],dp[i-1][0][1][0]);
			dp[i][1][0][0]=max(a[i][1],dp[i-1][1][0][0]);
			//dp[i][0][1][1]=max(a[i][2],a[i][3]);
			dp[i][0][1][1]=max(dp[i-1][0][0][1]+a[i][2],max(dp[i-1][0][1][0]+a[i][3],dp[i-1][0][1][1]));
			//dp[i][1][1][0]=max(a[i][1],a[i][2]);
			dp[i][1][1][0]=max(dp[i-1][1][0][0]+a[i][2],max(dp[i-1][0][1][0]+a[i][1],dp[i-1][1][1][0]));
			//dp[i][1][0][1]=max(a[i][1],a[i][3]);
			dp[i][1][0][1]=max(dp[i-1][0][0][1]+a[i][1],max(dp[i-1][1][0][0]+a[i][3],dp[i-1][1][0][1]));
			
		}
		for(int i=1;i<=n;i++){
			for(int x=2;x<=mid;x++){
				dp[i][0][0][x]=dp[i][0][0][x-1];
				dp[i][0][x][0]=dp[i][0][x-1][0];
				dp[i][x][0][0]=dp[i][x-1][0][0];
			}
		}
		for(int i=1;i<=n;i++){	
			for(int x1=1;x1<=mid;x1++)
				for(int x2=1;x2<=mid;x2++)
					for(int x3=1;x3<=mid;x3++){
						dp[i][x1][x2][x3]=max(max(dp[i-1][x1-1][x2][x3]+a[i][1],dp[i-1][x1][x2-1][x3]+a[i][2]),dp[i-1][x1][x2][x3-1]+a[i][3]);
					
						if(ans<dp[i][x1][x2][x3]) ans=dp[i][x1][x2][x3];
					}
		}/*
		for(int i=1;i<=n;i++)
			for(int x1=0;x1<=mid;x1++)
				for(int x2=0;x2<=mid;x2++)
					for(int x3=0;x3<=mid;x3++){
						cout<<i<<" "<<x1<<" "<<x2<<" "<<x3<<" "<<": "<<dp[i][x1][x2][x3]<<endl;
					}*/
		cout<<ans<<endl;
	}
	return 0;
}
/*
30
17553 12797 3374
2953 14912 58
7555 19831 2560
5097 13433 15072
1781 17711 18010
8299 18720 12018
14603 344 18111
998 14772 18326
19578 4037 3766
784 7896 12726
7146 7825 11703
10835 4567 12794
12486 11687 7166
14061 2677 17076
10303 9423 9254
10436 16190 10040
3017 5162 17384
2755 3755 17527
2078 4142 8428
18229 16100 2303
14554 6802 8514
6194 6065 17215
2753 17977 14174
3266 2088 17979
13615 17270 14852
11595 1443 5715
8506 1380 14666
3136 12361 19505
1387 19696 3983
18971 8142 9662
*/
