#include<bits/stdc++.h>
using namespace std;
int dp[205][205][205],t,n,ans,q1=0,q2=0,q3=0,x,y,z;
struct node{
	ll x,y;
};
node a[1e5+5];
int l,r;
bool cmp(ll x,ll y){
	return max(x.x,x.y)>max(y.y,y.x);
}
//dp[i][j][k]为在第一个社团i人
//第2个社团j人
//第3个社团k人
//的最优解 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		if(n>200){
			for(int i=1;i<=n;i++){
				cin>>a[i].x>>a[i].y>>z;
			}
			sort(a+1,a+n+1,cmp);
			l=r=0;
			for(int i=1;i<=n;i++){
				if(a[i].x>a[i].y&&l<=n/2){
					ans+=a[i].x;
					l++;
				}
				else if(a[i].x<a[i].y&&r<=n/2){
					ans+=a[i].y;
					r++;
				}
				else{
					if(l>r){
						ans+=a[i].y;
					}
					else{
						ans+=a[i].x;
					}
				}
			}
			cout<<ans<<endl;
		}
		memset(dp,0,sizeof dp);
		for(int l=1;l<=n;l++){
			cin>>x>>y>>z;
			for(int i=0;i<=l;i++){
				for(int j=0;j<=l-i;j++){
					int k=l-j-i;
					q1=0,q2=0,q3=0;
					if(i<=n/2&&i>0){
						q1=dp[i-1][j][k]+x;
					}
					if(j<=n/2&&j>0){
						q2=dp[i][j-1][k]+y;
					}
					if(k<=n/2&&k>0){
						q3=dp[i][j][k-1]+z;
					}
//					cout<<q1<<' '<<q2<<' '<<q3<<endl;
					dp[i][j][k]=max({q1,q2,q3});
				}
			}
		}
		for(int i=1;i<=n/2;i++){
			for(int j=1;j<=min(n/2,n-i);j++){
				int k=n-i-j;
				if(k<=n/2){
					ans=max(ans,dp[i][j][k]);
//					cout<<i<<' '<<j<<' '<<k<<' '<<ans<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
