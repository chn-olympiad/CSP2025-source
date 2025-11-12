#include<bits/stdc++.h>
using namespace std;
int t;
int n,ans,s[4];
struct node{
	int x[4],xm,xi;
}a[100010];
int dp[110][110][110];
bool cmp(node x,node y){
	return x.xm>y.xm;
}
void solve1(){
	ans=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i==j)continue;
			ans=max(a[1].x[i]+a[2].x[j],ans);
		}
	}
	cout<<ans<<endl;
}
void solve2(){
	ans=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++){
				for(int p=1;p<=3;p++){
					if((i==j&&j==k)||(i==j&&j==p)||(i==k&&k==p)||(j==k&&k==p))continue;
					ans=max(a[1].x[i]+a[2].x[j]+a[3].x[k]+a[4].x[p],ans);
				}
			}
		}
	}
	cout<<ans<<endl;
}
void dfs(int k,int cnt){
	if(k>n){
		ans=max(ans,cnt);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(s[i]<n/2){
			s[i]++;
			dfs(k+1,cnt+a[k].x[i]);
			s[i]--;
		}
	}
}
void solvexiao(){
	memset(dp,0,sizeof dp);
	ans=0;
	for(int i=1;i<=n;i++){
		for(int k1=n/2;k1>=0;k1--){
			for(int k2=n/2;k2>=0;k2--){
				for(int k3=n/2;k3>=0;k3--){
					if(k1!=0)dp[k1][k2][k3]=max(dp[k1][k2][k3],dp[k1-1][k2][k3]+a[i].x[1]);
					if(k2!=0)dp[k1][k2][k3]=max(dp[k1][k2][k3],dp[k1][k2-1][k3]+a[i].x[2]);
					if(k3!=0)dp[k1][k2][k3]=max(dp[k1][k2][k3],dp[k1][k2][k3-1]+a[i].x[3]);
					ans=max(ans,dp[k1][k2][k3]);
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x[1],&a[i].x[2],&a[i].x[3]);
			a[i].xm=max(max(a[i].x[1],a[i].x[2]),a[i].x[3]);
			if(a[i].xm==a[i].x[1])a[i].xi=1;
			else if(a[i].xm==a[i].x[2])a[i].xi=2;
			else if(a[i].xm==a[i].x[3])a[i].xi=3;
		}
		sort(a+1,a+1+n,cmp);
		s[1]=0,s[2]=0,s[3]=0,ans=0;
		if(n==2){
			solve1();
			continue;
		}
		if(n==4){
			solve2();
			continue;
		}
		if(n<=14){
			ans=0;
			dfs(1,0);
			cout<<ans<<endl;
			continue;
		}
		if(n<=200){
			solvexiao();
			continue;
		}
		for(int i=1;i<=n;i++){
			if(s[a[i].xi]+1<=n/2){
				s[a[i].xi]++;
				ans+=a[i].x[a[i].xi];
			}else {
				if(a[i].xi==1){
					if(a[i].x[2]<a[i].x[3]){
						s[3]++;
						ans+=a[i].x[3];
					}else{
						s[2]++;
						ans+=a[i].x[2];
					}
				}else if(a[i].xi==2){
					if(a[i].x[1]<a[i].x[3]){
						s[3]++;
						ans+=a[i].x[3];
					}else{
						s[1]++;
						ans+=a[i].x[1];
					}
				}else if(a[i].xi==3){
					if(a[i].x[2]<a[i].x[1]){
						s[1]++;
						ans+=a[i].x[1];
					}else{
						s[2]++;
						ans+=a[i].x[2];
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
