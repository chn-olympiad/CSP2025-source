#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define ll long long 
int t,n;
ll a[N][3],maxn[N],sum[3],ans;
vector<int> v;
void solve(){
	ans=0;
	scanf("%d",&n);
	v.clear();
	sum[0]=sum[1]=sum[2]=0;
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=0;j<=2;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j]>a[i][x]){
			   	x=j;
			}
		}
		maxn[i]=x;
		ans+=a[i][x];
		sum[x]++;
	}
	if(sum[0]<=n/2&&sum[1]<=n/2&&sum[2]<=n/2){
		printf("%lld\n",ans);
		return ;
	}
	int x;
	if(sum[0]>n/2){
		x=0;
	}else if(sum[1]>n/2){
		x=1;
	}else{
		x=2;
	}
	for(int i=1;i<=n;i++){
		if(maxn[i]==x){
			v.push_back(a[i][x]-max(a[i][(x+1)%3],a[i][(x+2)%3])); 
		}
	}
	sort(v.begin(),v.end());
	for(int i=0;i<sum[x]-n/2;i++){
		ans-=v[i];
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		solve();
	}
	
	return 0;
}
//Ren5Jie4Di4Ling5% 
/*3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
