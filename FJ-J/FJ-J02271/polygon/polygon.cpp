//Nov_1_9:59_AK_CSP-J
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int Rd;

inline Rd read(){Rd xxx=0,yyy=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')yyy*=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){xxx=(xxx<<1)+(xxx<<3)+(ch^48);ch=getchar();}
return xxx*yyy;
}

const int maxn=5005,maxx=5000,mod=998244353;

int n;
int a[maxn];
ll dp1[maxn],dp2[maxn],dp[maxn],ans;
//the_xb_means_the_sum & xb==maxx+1_means_sum>5000
//dp1:one val
//dp2:two val
//dp:three&more val

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	/*动态规划优化*/
	cin>>n;
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	//in_it & sort_it
	for(int i=1;i<=n;i++){
		for(int j=maxx+1;j>a[i];j--)//the_a[i]_will_be_the_max
			ans=(ans+dp[j]+dp2[j])%mod;
		
		dp[maxx+1]=dp[maxx+1]*2ll%mod;
		for(int j=maxx+a[i];j-a[i]>=0;j--)
			dp[min(j,maxx+1)]=(dp[min(j,maxx+1)]+dp[j-a[i]])%mod;
		//dp<-dp
		
		dp[maxx+1]=(dp[maxx+1]+dp2[maxx+1])%mod;
		for(int j=maxx+a[i];j-a[i]>=0;j--)
			dp[min(j,maxx+1)]=(dp[min(j,maxx+1)]+dp2[j-a[i]])%mod;
		//dp<-dp2
		
		dp2[maxx+1]=(dp2[maxx+1]*2ll)%mod;
		for(int j=maxx+a[i];j-a[i]>=0;j--)
			dp2[min(j,maxx+1)]=(dp2[min(j,maxx+1)]+dp1[j-a[i]])%mod;
		//dp2<-dp1
		
		dp1[a[i]]++;
		//update dp1
		//U_should_follow_the_order or fail_the_CSP-J
	}
	//solve
	cout<<ans;
	//put_it
	return 0;
}
/*

woc, it's so boring .I think CCF has put so much water.
oh damn!I have 2h to sleep , but I'm so excited ,I can't sleep.
I want to do homwork!
I want to do homwork!
I want to do homwork!
I want to do homwork!
I make up my mind to ba a pro grandma.
_Brian0510_11.01_

*/
