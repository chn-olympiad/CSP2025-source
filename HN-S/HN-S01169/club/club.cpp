#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,a[N],b[N],c[N],ans;
void dfs(int t,int cnt_a,int cnt_b,int cnt_c,int sum){
	if(t==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(cnt_a+1<=n/2)
		dfs(t+1,cnt_a+1,cnt_b,cnt_c,sum+a[t]);
	if(cnt_b+1<=n/2)
		dfs(t+1,cnt_a,cnt_b+1,cnt_c,sum+b[t]);
	if(cnt_c+1<=n/2)
		dfs(t+1,cnt_a,cnt_b,cnt_c+1,sum+c[t]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;ans=0;
		int flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(c[i]||b[i])flag=0;
		}
		if(flag){
			sort(a+1,a+n+1,greater<int>());
			for(int i=1;i<=n/2;i++)
				ans+=a[i];
			cout<<ans<<'\n';
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}

