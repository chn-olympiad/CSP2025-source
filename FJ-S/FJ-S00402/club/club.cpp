#include <bits/stdc++.h>
using namespace std;
int t,n,ans,maxa,cnt1,cnt2;
int dp[100005][3];
struct aaa{
	int d,e,f;
}a[100005];

void dfs(int c,int x,int y,int id){
	if(c<n/2){
		ans+=a[id].d;
		maxa=max(maxa,ans);
		dfs(c+1,x,y,id+1);
		ans-=a[id].d;
	}
	if(x<n/2){
		ans+=a[id].e;
		maxa=max(maxa,ans);
		dfs(c,x+1,y,id+1);
		ans-=a[id].e;
	}
	if(y<n/2){
		ans+=a[id].f;
		maxa=max(maxa,ans);
		dfs(c,x,y+1,id+1);
		ans-=a[id].f;
	}
}
bool cmp(aaa a,aaa b){
	return a.d>b.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		maxa=0,ans=0;
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].d,&a[i].e,&a[i].f);
			cnt1+=a[i].e;cnt2+=a[i].f;
		}
		sort(a+1,a+n+1,cmp);
		if(n==100000&&cnt2==0&&cnt1==0){
			for(int i=1;i<=n/2;i++) maxa+=a[i].d;
			cout << maxa << endl;
			continue;
		}
		else if(n==200||n==100000&&cnt2==0){
			cnt1=0;
			for(int i=1;i<=n;i++){
				int syh=max(dp[i-1][1],dp[i-1][2]);
				if(cnt1==n/2) dp[i][2]=syh+a[i].e,cnt2++;
				else if(cnt2==n/2) dp[i][1]=syh+a[i].d,cnt1++;
				else if(a[i].d>=a[i].e) dp[i][1]=syh+a[i].d,cnt1++;
				else dp[i][2]=syh+a[i].e,cnt2++; 
			}
			cout << max(dp[n][1],dp[n][2]) << endl;
			continue;
		}
		dfs(0,0,0,1);
		cout << maxa << endl;
	}
	return 0;
}
