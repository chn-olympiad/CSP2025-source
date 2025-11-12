#include<bits/stdc++.h>
using namespace std;

int n,t,ans=0;

struct student{
	int yi,er,san;
	int zdd=0;
}d[100010];

void dfs(int x,int y,int e,int s,int sx,int sum){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	if(y<sx)dfs(x+1,y+1,e,s,sx,sum+d[x].yi);
	if(e<sx)dfs(x+1,y,e+1,s,sx,sum+d[x].er);
	if(s<sx)dfs(x+1,y,e,s+1,sx,sum+d[x].san);
}

bool cmp(student a,student b){
	return a.zdd>b.zdd;
}

void solve(){
	sort(d+1,d+n+1,cmp);
	int l;
	l=n/2;
	for(int i=1;i<=l;i++){
		ans+=d[i].yi;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[i].yi>>d[i].er>>d[i].san;
			d[i].zdd=max(d[i].yi,max(d[i].er,d[i].san));
		}
		if(n<=30)dfs(1,0,0,0,n/2,0);
		else solve();
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)d[i].yi=d[i].er=d[i].san=0;
	}
	return 0;
}
