#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[5005],dp[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[n]+1;j>=0;j--){
			if(j>a[i]) ans=(ans+dp[j])%MOD;
			if(j+a[i]>a[n]) dp[a[n]+1]=(dp[a[n]+1]+dp[j])%MOD;
			else dp[j+a[i]]=(dp[j+a[i]]+dp[j])%MOD;
		}
	}
	cout<<ans;
	return 0;
}
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
//Never gonna give you up! My Honkai Star Rail(OO:OOOO) UID is 158184107!
//怎么9:19就写完4道了。我甚至看了10min题才开始写ww（因为win键用不了等修结果老师说修不了） 
//造大样例去了。Win键用不了好难受。 
//知更鸟小姐，我是你的粉丝啊！
//纯默写 我英语不好致歉。 
//i'm not good at English... 
//let my heart bravely spread the wings
//soaring past the night
//to trace the bright moonlight
//let the cloud heal me of the stings
//gently wipe the sorrow of my life
//i dream
//知更鸟小姐保佑我AK！qwq 
