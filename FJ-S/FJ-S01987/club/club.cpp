#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int T,n,a[N][5],c[N];
ll ans;
void dfs(int i,int x,int y,int z,ll sum){
	if(x>n/2||y>n/2||z>n/2)return;
	if(i==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int j=1;j<=3;j++)
		dfs(i+1,x+(j==1),y+(j==2),z+(j==3),sum+a[i][j]);
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)c[i]=0;
	vector<int>v;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
			scanf("%d",&a[i][j]),v.push_back(a[i][1]);
	if(n<=10){ans=0;dfs(1,0,0,0,0);printf("%lld\n",ans);return;};	
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		int mid=n/2;
		ll res=0;
		for(auto s:v){
			res+=s;mid--;if(!mid)break;
		}
		printf("%lld\n",res);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&T);
	for(;T--;)solve();
	return 0;
} 
