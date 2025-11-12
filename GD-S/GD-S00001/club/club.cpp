#include<bits/stdc++.h>
using namespace std;
struct qq{
	int aa,b,c;
}a[100005];
int n;
int ans=0;
int dp[35][20][20][20];
int d,e,f;
void so1(){
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n/2;j++)
			for(int k=0;k<=n/2;k++)
				for(int x=0;x<=n/2;x++){
					if(j>=1)dp[i][j][k][x]=dp[i-1][j-1][k][x]+a[i].aa;
					if(k>=1)dp[i][j][k][x]=max(dp[i][j][k][x],dp[i-1][j][k-1][x]+a[i].b);
					if(x>=1)dp[i][j][k][x]=max(dp[i][j][k][x],dp[i-1][j][k][x-1]+a[i].c);
					if(ans<dp[i][j][k][x])ans=max(ans,dp[i][j][k][x]),d=j,e=k,f=x;
				}
	cout<<ans<<endl;
	return;
}
bool cmp(qq a,qq bb){
	return a.aa>bb.aa; 
}
void so2(){
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n/2;i++)ans+=a[i].aa;
	cout<<ans<<endl;
	return;
}
bool cmp1(qq a,qq bb){
	return a.aa-a.b>bb.aa-bb.b;
}
void so3(){
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<=n/2;i++)ans+=a[i].aa;
	for(int i=n/2+1;i<=n;i++)ans+=a[i].b;
	cout<<ans<<endl;
	return;
}
void work(){
	cin>>n;
	int fl1=1,fl2=1;
	for(int i=1;i<=n;i++)cin>>a[i].aa>>a[i].b>>a[i].c;
	for(int i=1;i<=n;i++){
		if(a[i].b!=0)fl2=0;
		if(a[i].c!=0)fl1=fl2=0;
	}
	if(fl2)so2();
	else if(fl1)so3();
	else so1();
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		ans=0;
		work();
	}
	return 0;
}
