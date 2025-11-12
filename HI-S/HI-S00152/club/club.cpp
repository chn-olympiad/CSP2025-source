#include<bits/stdc++.h>
using namespace std;
int t,a[1000010][5],n,ans=-2e9,book[50][50][50][50]; 
void dfs(int cnt,int sum,int al,int bl,int cl){
	if(cnt==n+1){
		if(al<=n/2&&bl<=n/2&&cl<=n/2) ans=max(ans,sum);
		return;
	}
	if(book[cnt][al][bl][cl]<=sum) book[cnt][al][bl][cl]=sum;
	else return;
	if(al<=n/2) dfs(cnt+1,sum+a[cnt][1],al+1,bl,cl);
	if(bl<=n/2) dfs(cnt+1,sum+a[cnt][2],al,bl+1,cl);
	if(al<=n/2) dfs(cnt+1,sum+a[cnt][3],al,bl,cl+1);
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=-2e9;
		memset(book,0,sizeof(book));
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}

