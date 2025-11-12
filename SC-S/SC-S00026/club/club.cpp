#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll t,n,dp[2][110][110][110];
struct node{
	ll x,y,z;
}a[100000+10];
bool cmp(node n1,node n2){
	return n1.x>n2.x;
}
bool cmp2(node n1,node n2){
	return n1.y>n2.y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ll f1=0,f2=0;
		memset(dp,0,sizeof(dp));
		for(ll i=1;i<=n;i++){ 
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0) f1=1;
			if(a[i].z!=0) f1=1,f2=1;
		}
		if(f1==0){
			sort(a+1,a+n+1,cmp);
			ll ans=0;
			for(ll i=1;i<=n/2;i++) ans+=a[i].x;
			cout<<ans<<endl;
			continue;
		}
		if(f2==0){
			ll dpp[210][110][110]={};
			for(ll i=1;i<=n;i++){
				for(ll aa=0;aa<=n/2;aa++){
					ll b=i-aa;
					if(b<0 || b>n/2) continue;
					ll MAX=-0x3f;
					if(aa>0) MAX=max(dpp[i-1][aa-1][b]+a[i].x,MAX);
					if(b>0) MAX=max(dpp[i-1][aa][b-1]+a[i].y,MAX);
					dpp[i][aa][b]=MAX;
				}
			}
			cout<<dpp[n][n/2][n/2]<<endl;
			continue;
		}
		for(ll i=1;i<=n;i++){
			for(ll aa=0;aa<=n/2;aa++){
				for(ll b=0;b<=n/2;b++){
					ll c=i-aa-b;
					if(c<0 || c>n/2) continue;
					ll MAX=-0x3f;
					if(aa>0) MAX=max(dp[0][aa-1][b][c]+a[i].x,MAX);
					if(b>0) MAX=max(dp[0][aa][b-1][c]+a[i].y,MAX);
					if(c>0) MAX=max(dp[0][aa][b][c-1]+a[i].z,MAX);
					dp[1][aa][b][c]=MAX;
				}
			}
			for(ll aa=0;aa<=n/2;aa++) for(ll b=0;b<=n/2;b++) if(i-aa-b>=0 && i-aa-b<=n/2) dp[0][aa][b][i-aa-b]=dp[1][aa][b][i-aa-b];
		} 
		ll Max=INT_MIN;
		for(ll aa=0;aa<=n/2;aa++){
			for(ll b=0;b<=n/2;b++){
				if(n-aa-b<=n/2) Max=max(Max,dp[1][aa][b][n-aa-b]);
			}
		}
		cout<<Max<<endl;
	}
	return 0;
}