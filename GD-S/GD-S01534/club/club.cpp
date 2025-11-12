#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long x,id;
}a[100005][3];
long long T,n,cnt[3];
bool cmp(edge xr,edge y){ return xr.x>y.x; }
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		priority_queue<long long,vector<long long>,greater<long long>> g[3];
		long long ans=0;
		for(long long i=0;i<=2;i++)cnt[i]=0;
		for(long long i=1;i<=n;i++){
			for(long long j=0;j<=2;j++){
				cin>>a[i][j].x,a[i][j].id=j;
			}
			sort(a[i]+0,a[i]+0+3,cmp);
		}
		bool flag=true;
		for(long long i=1;i<=n;i++){
			cnt[a[i][0].id]++;
			flag&=cnt[a[i][0].id]<=(n/2);
			ans+=a[i][0].x;
			g[a[i][0].id].push(a[i][0].x-a[i][1].x);
		}
		if(flag){
			cout<<ans<<'\n';
			continue;
		}
		for(long long i=0;i<=2;i++){
			if(cnt[i]>n/2){
				for(;cnt[i]>n/2;){
					ans-=g[i].top();
					g[i].pop();
					cnt[i]--;
				}
			}
		}
		cout<<ans<<'\n';
	}
} 
