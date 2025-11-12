#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+9;
int T,minn[maxn][4];
struct node{
	int index,sum,num;
}a[maxn][4];
bool cmp(node x,node y){
	return x.sum<y.sum;
}
struct node1{
	int sum,index,num;
}maxx[maxn];
bool cmp1(node1 x,node1 y){
	return x.sum<y.sum;
}
void solve(){
	int n,ans=0,vis[4];
	vector<int >vis1[4];
	memset(vis,0,sizeof(vis));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1].sum>>a[i][2].sum>>a[i][3].sum;
		a[i][1].index=1,a[i][2].index=2,a[i][3].index=3;
		minn[1][i]=min(abs(a[i][1].sum-a[i][2].sum),abs(a[i][1].sum-a[i][3].sum));
		minn[2][i]=min(abs(a[i][2].sum-a[i][1].sum),abs(a[i][2].sum-a[i][3].sum));
		minn[3][i]=min(abs(a[i][3].sum-a[i][2].sum),abs(a[i][3].sum-a[i][1].sum));
		sort(a[i]+1,a[i]+4,cmp);
		maxx[i].sum=a[i][3].sum,maxx[i].index=a[i][3].index;
		maxx[i].num=minn[maxx[i].index][i];
	}
	sort(maxx+1,maxx+1+n,cmp1);
	for(int i=n;i>=1;i--){
		ans+=maxx[i].sum;
		vis[maxx[i].index]++;
		vis1[maxx[i].index].push_back(maxx[i].num);
	}
	for(int i=1;i<=3;i++){
		if(vis[i]>n/2){
			sort(vis1[i].begin(),vis1[i].end());
			for(int j=0;j<vis[i]-n/2;j++){
				ans-=vis1[i][j];
			}
			cout<<ans<<endl;
			return ;
		}
	}
	cout<<ans<<endl;
	return ;
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
