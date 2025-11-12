#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int a[100005][5];
bool pf_1_flag;
void dfs(int now,int cnt1,int cnt2,int cnt3,int sum){
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2)
		return ;
	if(now==n+1){
		ans=max(ans,sum);
		return ;
	}
	dfs(now+1,cnt1+1,cnt2,cnt3,sum+a[now][1]);
	dfs(now+1,cnt1,cnt2+1,cnt3,sum+a[now][2]);
	dfs(now+1,cnt1,cnt2,cnt3+1,sum+a[now][3]);
}
void tsxzA(){
	for(int i=1;i<=n;i++)
		if(a[i][2]!=0||a[i][3]!=0) return ;
	int pf[100005]={0},tot=0;
	for(int i=1;i<=n;i++)
		pf[i]=a[i][1];
	sort(pf+1,pf+n+1,greater<int>());
	for(int i=1;i<=n/2;i++)
		tot+=pf[i];
	printf("%d",tot);
	pf_1_flag=true;
	return ;
}
void solve(){
	ans=0;
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	//ÌØÊâÐÔÖÊA 
	pf_1_flag=false;
	tsxzA();
	if(pf_1_flag==true) return ;
	
	dfs(1,0,0,0,0);
	printf("%d\n",ans);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
		solve();
	
	return 0;
} 
