#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+7;
struct node{
	int x,y,dif;
	bool operator<(node w){
		return x>w.x;
	}
};
int t,n,a[N][5],ans;

void dfs(int x,int y,int z,int cnt){
	if(x+y+z==n){
		ans=max(ans,cnt);
		return;
	}
	if(x+1<=n/2) dfs(x+1,y,z,cnt+a[x+y+z+1][1]);
	if(y+1<=n/2) dfs(x,y+1,z,cnt+a[x+y+z+1][2]);
	if(z+1<=n/2) dfs(x,y,z+1,cnt+a[x+y+z+1][3]);
}

void solve(){
	cin>>n;
	int mxa=0,mxb=0,mxc=0;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		mxa=max(mxa,a[i][1]),mxb=max(mxb,a[i][2]),mxc=max(mxc,a[i][3]);
	}
	if(mxb==0&&mxc==0){
		int c[N];
		for(int i=1;i<=n;i++) c[i]=a[i][1];
		sort(c+1,c+n+1);
		for(int i=n;i>n/2;i--) ans+=c[i];
	} else if(mxc==0){
		node c[N];
		for(int i=1;i<=n;i++) c[i]={a[i][1],a[i][2],abs(a[i][1]-a[i][2])};
		sort(c+1,c+n+1);
		int l=n/2,r=n/2;
		for(int i=1;i<=n;i++){
			if(c[i].x>c[i].y){
				if(l) ans+=c[i].x,l--;
				else ans+=c[i].y,r--;
			} else{
				if(r) ans+=c[i].y,r--;
				else ans+=c[i].x,l--;
			}
		}
	} else dfs(0,0,0,0);
	cout<<ans<<"\n";
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
