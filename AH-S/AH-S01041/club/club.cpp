#include<bits/stdc++.h>
using namespace std;
int T,n,ans,fg;
struct node{
	int c1,c2,c3;
}a[100005];
void dfs(int now,int s1,int s2,int s3,int sum){
	if(now==n+1){
		ans=max(ans,sum);
		return;
	}
	if(s1+1<=n/2) dfs(now+1,s1+1,s2,s3,sum+a[now].c1);
	if(s2+1<=n/2) dfs(now+1,s1,s2+1,s3,sum+a[now].c2);
	if(s3+1<=n/2) dfs(now+1,s1,s2,s3+1,sum+a[now].c3);
}
bool cmp(node k1,node k2){
	return k1.c2>k2.c2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0,fg=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].c1,&a[i].c2,&a[i].c3);
			if(a[i].c2!=0||a[i].c3!=0) fg=0;
		}
		if(fg){
			sort(a+1,a+n+1,cmp);
			int all=0;
			while(all<=n/2){
				all++;
				ans+=a[all].c2;
			}
			cout<<ans<<endl;
			continue;
		}
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
