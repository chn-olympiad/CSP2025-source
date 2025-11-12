#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,x;
}a[1000005];
int t,n,ans,dp[205][205][205];
void dfs(int x,int aa,int bb,int s){
//	cout<<x<<" "<<aa<<" "<<bb<<" "<<s<<"\n";
	if(x==n+1){
		if(aa>n/2||bb>n/2||n-aa-bb>n/2)return ;
		ans=max(ans,s);
		return ;
	}
	if(dp[x][aa][bb]>=s){
		return ;
	}
	else{
		dp[x][aa][bb]=s;
	}
	dfs(x+1,aa+1,bb,s+a[x].a);
	dfs(x+1,aa,bb+1,s+a[x].b);
	dfs(x+1,aa,bb,s+a[x].c);
}
bool cmp(node a,node b){
	return a.a>b.b;
}
bool ccmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>t;
	while(t--){
		memset(dp,-0x3f,sizeof(dp));
		ans=0;
		cin>>n;
		int flag=1,falg=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].x=a[i].a-a[i].b;
			if(a[i].b||a[i].c)flag=0;
			if(a[i].c)falg=0;
		}
		if(flag==1)falg=0;
		if(n<=200){
			dfs(1,0,0,0);
			cout<<ans<<"\n";
		}
		else if(flag){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			cout<<ans<<"\n";
		}
		else if(falg){
			sort(a+1,a+n+1,ccmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i].b;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
