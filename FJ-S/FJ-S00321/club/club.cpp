#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e5+5;
int t,n,a[N],b[N],c[N],cnt[3],ans;
void dfs(int k,int tot){
	if(k>n){
		ans=max(tot,ans);
		return;
	}
	if(cnt[0]<n/2){
		cnt[0]++;
		dfs(k+1,tot+a[k]);
		cnt[0]--;
	}
	if(cnt[1]<n/2){
		cnt[1]++;
		dfs(k+1,tot+b[k]);
		cnt[1]--;
	}
	if(cnt[2]<n/2){
		cnt[2]++;
		dfs(k+1,tot+c[k]);
		cnt[2]--;
	}
}
void init(){
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
	dfs(1,0);
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++) init();
	return 0;
}
