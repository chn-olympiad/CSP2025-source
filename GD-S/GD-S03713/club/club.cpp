#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string renpin="66666666666666666666666666666666";
ll t;
ll dp[100010];
struct stu{
	ll d[5];
}a[100010];
bool cmp(stu a,stu b){
	return a.d[1]>b.d[1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//cout<<renpin;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof dp);
		ll n,s[]={0,0,0,0};
		cin>>n;
		bool f=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
			if(a[i].d[2]!=0||a[i].d[3]!=0){
				f=0;
			}
		}
		if(f){
			sort(a+1,a+n+1,cmp);
			int m=n/2;
			int ans=0;
			for(int i=1;i<=n;i++){
				if(m>0){
					ans+=a[1].d[1];
					m--;
				}
			}
			cout<<ans<<'\n';
		}else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					if(s[j]<=n/2){
						if(dp[i]<dp[i-1]+a[i].d[j]){
							dp[i]=dp[i-1]+a[i].d[j];
							s[j]++;
						}
						//cout<<i<<':'<<dp[i]<<'\n';
					}
				}
			}
			cout<<dp[n]<<'\n';
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
/*
      ·ð×æ±£ÓÓ
         /@\
	    @@@@
       |- -|
       | _ |
     __\__/__
    /  /  \  \
   | | /|\ |  |
   |  || |||  |
   \__| | \__/
    \______/
 |\ /\ /\ /\ /|
 \_/_\/_\/_\_/
  \_________/
*/
