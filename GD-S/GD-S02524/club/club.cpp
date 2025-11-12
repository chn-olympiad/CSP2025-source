#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int cost,b;
}c[100005];
int t,n,ans,cnt[10],d[10],a[100005][4];
bool cmp(node a,node b){
	return a.cost>b.cost;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			d[1]=a[i][1];d[2]=a[i][2];d[3]=a[i][3];
			sort(d+1,d+4);
			ans+=d[3];
			c[i].cost=d[3]-d[2];
			if(d[3]==a[i][1])c[i].b=1;
			else if(d[3]==a[i][2])c[i].b=2;
			else c[i].b=3;
		}
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[c[i].b]==n/2)ans-=c[i].cost;
			else cnt[c[i].b]++;
		}
		cout<<ans<<'\n';
	}
	
} 
