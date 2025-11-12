#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
struct node{
	int ls1,ls2,id,pos;
}a[maxn*3];
bool cmp(node a,node b){
	return min(a.ls1,a.ls2)>min(b.ls1,b.ls2);
}
int t,n,tot,og[maxn][4];
bool vis[maxn];
void init(){
	tot=0;
	memset(vis,0,sizeof vis);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1,t1,t2,t3;i<=n;i++){
			scanf("%lld%lld%lld",&t1,&t2,&t3);
			og[i][1]=t1,og[i][2]=t2,og[i][3]=t3;
			a[++tot]={t1-t2,t1-t3,1,i};
			a[++tot]={t2-t1,t2-t3,2,i};
			a[++tot]={t3-t1,t3-t2,3,i};
		}
		sort(a+1,a+3*n+1,cmp);
		int cnt[5]={0},ans=0;
		for(int i=1;i<=3*n;i++){
			if(cnt[a[i].id]<(n/2)&&!vis[a[i].pos]){
				ans+=og[a[i].pos][a[i].id];
				cnt[a[i].id]++; 	
				vis[a[i].pos]=1;
//				cout<<a[i].pos<<" "<<a[i].id<<"\n";
			}
		}
		cout<<ans<<"\n";
		init();
	}
}
