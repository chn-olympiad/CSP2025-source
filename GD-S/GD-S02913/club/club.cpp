#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m;
struct node{
	int x,y,z;
}a[N];
ll ans;
bool cmp(const node &x,const node &y){
	return x.x>y.x;
}
inline void dfs(int k,ll x,ll y,ll z,ll sum){
	if(k>n){
		ans=max(ans,sum);
		return;
	}
	if(x<m)
		dfs(k+1,x+1,y,z,sum+a[k].x);
	if(y<m)
		dfs(k+1,x,y+1,z,sum+a[k].y);
	if(z<m)
		dfs(k+1,x,y,z+1,sum+a[k].z);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		ans=0;
		ll sum1=0,sum2=0,sum3=0;
		scanf("%d",&n);
		m=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].x)sum1++;
			if(a[i].y)sum2++;
			if(a[i].z)sum3++;
		}
		if(sum2==0&&sum3==0){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i*2<=n;i++)
				ans+=a[i].x;
			printf("%lld\n",ans);
		}else{
			dfs(1,0,0,0,0);
			printf("%lld\n",ans);
		}
	} 
	return 0;
}
