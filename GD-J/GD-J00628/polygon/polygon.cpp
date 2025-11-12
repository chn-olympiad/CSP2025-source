#include<bits/stdc++.h>
using namespace std;
long long a[5010],n,ans;
void dfs(long long m,long long cnt,long long maxn,long long g){
	if(m==n&&cnt>maxn*2&&g>2){
		ans++;
		return;
	}
	if(m>n||g>n)return;
	dfs(m+1,cnt,maxn,g);
	dfs(m+1,cnt+a[m+1],max(a[m+1],maxn),g+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans%998244353;
	return 0;
} 

