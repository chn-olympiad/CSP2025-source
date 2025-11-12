#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ty{
	int a,b,c,z;
}dp[100005];
bool comp(int x,int y){
	return x>y;
}
bool com(ty x,ty y){
	return x.a>y.a;
}
bool co(ty x,ty y){
	return x.b>y.b;
}
void test(){
	int n;
	cin>>n;
	bool an=0,en=0;
	for(int i=1;i<=n;i++){
		cin>>dp[i].a>>dp[i].b>>dp[i].c;
		dp[i].z=i;
		if(dp[i].b!=0) an=1;
		if(dp[i].c!=0) en=1;
	}
	//sort(dp+1,dp+1+n;comp);
	if(n==2){
		ll l[10];
		l[1]=dp[1].a+dp[2].b;
		l[2]=dp[1].a+dp[2].c;
		l[3]=dp[1].b+dp[2].a;
		l[4]=dp[1].b+dp[2].c;
		l[5]=dp[1].c+dp[2].a;
		l[6]=dp[1].c+dp[2].b;
		sort(l+1,l+1+6,comp);
		cout<<l[1]<<endl;
		return;
	}
	if(an==0&&en==0){
		sort(dp+1,dp+1+n,com);
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans+=dp[i].a;
		}
		cout<<ans<<endl;
		return;
	}
	if(an!=0&&en==0&&n>2){
		sort(dp+1,dp+1+n,com);
		ll ans=0,ans1=0;
		for(int i=1;i<=n/2;i++){
			ans+=dp[i].a;
		}
		for(int i=n/2+1;i<=n;i++){
			ans1+=dp[i].a;
		}
		sort(dp+1,dp+1+n,co);
		ll num=0,num1=0;
		for(int i=1;i<=n/2;i++){
			num+=dp[i].b;
		}
		for(int i=n/2+1;i<=n;i++){
			num1+=dp[i].b;
		}
		if(ans>num){
			cout<<ans+num1<<endl;
			return;
		}
		if(num>ans){
			cout<<num+ans1<<endl;
			return;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
	while(t--) test();
	return 0;
}

