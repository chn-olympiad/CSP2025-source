#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
long long ans=0;
int a[N][4],st[4];
void dfs(int x,long long cnt){
	if(st[1]>n/2||st[2]>n/2||st[3]>n/2)
	if(x==n+1){
		ans=max(ans,cnt);
		return ;
	}
	st[1]++;
	dfs(x+1,cnt+a[x][1]);
	st[1]--;
	st[2]++;
	dfs(x+1,cnt+a[x][2]);
	st[2]--;
	st[3]++;
	dfs(x+1,cnt+a[x][3]);
	st[3]--;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
} 
