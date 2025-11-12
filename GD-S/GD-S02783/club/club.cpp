#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[4],dp[100010][3];
struct node{
	int x,y,z,Max;
}a[100010];
bool cmp(node u,node v){
	return u.Max>v.Max;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].Max=max(a[i].x,max(a[i].y,a[i].z));
		}
		sort(a+1,a+n+1,cmp);
		dp[1][0]=a[1].x;
		dp[1][1]=a[1].y;
		dp[1][2]=a[1].z;
		for(int i=2;i<=n;i++){
			if(cnt[1]>1){
				dp[i][0]=max(dp[i-1][1],dp[i-1][2]);
				dp[i][0]+=a[i].x;
				if(dp[i-1][0]+a[i].x>dp[i][0]){
					dp[i][0]=dp[i-1][0]+a[i].x;
					cnt[1]--;
				}
			}
			else if(cnt[1]==1){
				dp[i][0]=max(a[i].x+dp[i-1][1],a[i].x+dp[i-1][2]);
				if(dp[i-1][0]>dp[i][0]){
					dp[i][0]=dp[i-1][0];
				}
				cnt[1]--;
			}
			else dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
			if(cnt[2]>1){
				dp[i][1]=max(dp[i-1][0],dp[i-1][2]);
				dp[i][1]+=a[i].y;
				if(dp[i-1][1]+a[i].y>dp[i][1]){
					dp[i][1]=dp[i-1][1]+a[i].y;
					cnt[2]--;
				}
			}
			else if(cnt[2]==1){
				dp[i][1]=max(a[i].y+dp[i-1][0],a[i].y+dp[i-1][2]);
				if(dp[i-1][1]>dp[i][1]){
					dp[i][1]=dp[i-1][1];
				}
				cnt[2]--;
			}
			else dp[i][1]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
			if(cnt[3]>1){
				dp[i][2]=max(dp[i-1][1],dp[i-1][0]);
				dp[i][2]+=a[i].z;
				if(dp[i-1][2]+a[i].z>dp[i][2]){
					dp[i][2]=dp[i-1][2]+a[i].z;
					cnt[3]--;
				}
			}
			else if(cnt[3]==1){
				dp[i][2]=max(a[i].z+dp[i-1][1],a[i].z+dp[i-1][0]);
				if(dp[i-1][2]>dp[i][2]){
					dp[i][2]=dp[i-1][2];
				}
				cnt[3]--;
			}
			else dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
		}
		cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
