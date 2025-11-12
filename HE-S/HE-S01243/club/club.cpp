#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][4],cnt[4];
int dfs(int x,int sum){
	if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2)return -1;
	if(x>=n)return sum;
	int ans=-1;
	for(int i=1;i<=3;i++)
		cnt[i]++,ans=max(ans,dfs(x+1,sum+a[x][i])),cnt[i]--;
	return ans;
}
void solve(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	cout<<dfs(0,0)<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
