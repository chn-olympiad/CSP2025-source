#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool f1=true;
int t,n,ans;
int tmp[100010];
int a[100010][4];
struct stu{int num,l[4];};
stu dp[100010][4];
void dfs(int cur,int sum,int l1,int l2,int l3){
	if(cur>n){
		ans=max(ans,sum);
		return ;
	}
	if(l1+1<=n/2) dfs(cur+1,sum+a[cur][1],l1++,l2,l3);
	if(l2+1<=n/2) dfs(cur+1,sum+a[cur][2],l1,l2++,l3);
	if(l3+1<=n/2) dfs(cur+1,sum+a[cur][3],l1,l2,l3++);
}
void dps(){
	for(int i=1;i<=n;i++){
		int last=0;
		for(int j=1;j<=3;j++) last=max(last,dp[i-1][j].num);
		for(int j=1;j<=3;j++){
			if(dp[i-1][1].l[j]+1 <= n/2){
				dp[i][j].num=last+a[i][j];
				dp[i][j].l[j]++;
			}else dp[i][j]=dp[i-1][j];
		}
	}
	for(int j=1;j<=3;j++) ans=max(ans,dp[n][j].num);
	cout<<ans<<endl;
	memset(dp,0,sizeof(dp));
}
void fun1(){
	int ans=0;
	for(int i=1;i<=n;i++) tmp[i]=a[i][1];
	sort(tmp+1,tmp+n+1);
	for(int i=1;i<=n/2;i++) ans+=tmp[i];
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}	
			if(a[i][2]!=0 || a[i][3]!=0) f1=false;
		}	
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
		else if(f1) fun1();
		else dps();
		cout<<ans<<endl; ans=0;
	}
	return 0;
}
