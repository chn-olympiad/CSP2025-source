#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,cnt;
struct node{
	long long x,y,z;
}a[100100];
void dfs(long long now,long long cnt,long long c1,long long c2,long long c3){
	if (now>n){
		ans=max(ans,cnt);
		return ;
	}
	for (int i=1;i<=3;i++){
		if (c1<n/2){
			dfs(now+1,cnt+a[now].x,c1+1,c2,c3);
		}
		if (c2<n/2){
			dfs(now+1,cnt+a[now].y,c1,c2+1,c3);
		}
		if (c3<n/2){
			dfs(now+1,cnt+a[now].z,c1,c2,c3+1);
		}
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		ans=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
