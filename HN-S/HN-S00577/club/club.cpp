#include<bits/stdc++.h>
#define int long long
const int kMaxN=1e5+5;
using namespace std;
int T,n;
struct node{
	int x,y,z;
}a[kMaxN];
int maxn=INT_MIN;
void dfs(int i,int sum,int x,int y,int z){
	if(x>n/2||y>n/2||z>n/2)return;
	if(i>n){
		maxn=max(maxn,sum);
		return;
	}
	dfs(i+1,sum+a[i].x,x+1,y,z);
	dfs(i+1,sum+a[i].y,x,y+1,z);
	dfs(i+1,sum+a[i].z,x,y,z+1);
	return;
}

bool cmp(node a,node b){
	return a.x<b.x;
}
priority_queue<int>q[3];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int ans=0;
		maxn=INT_MIN;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].x>>a[i].y>>a[i].z;
		bool flagA=false;
		for(int i=1;i<=n;i++)
			if(a[i].y!=0&&a[i].z!=0)
				flagA=true;
		if(flagA){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			cout<<ans;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<maxn<<'\n';
		continue;
	}
	return 0;
}
/*
*/
