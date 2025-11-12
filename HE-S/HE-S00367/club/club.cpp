#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+3;
int T,n;
struct zzz{
	int y,xid,yid;
}e[N];
int a,b,c;
bool cmp(zzz x,zzz y){
	return x.y<y.y;
}
int ans=0;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			int ma=max(max(a,b),c);
			ans+=ma;
			a-=ma;
			b-=ma;
			c-=ma;
			if(a>b&&a>c){
				e[i].xid=1;
				if(b>c){
					e[i].yid=2;
					e[i].y = b;
				}else{
					e[i].yid=3;
					e[i].y = c;
				}
			}else if(b>a&&b>c){
				e[i].xid=2;
				if(a>c){
					e[i].yid=1;
					e[i].y = a;
				}else{
					e[i].yid=3;
					e[i].y = c;
				}
			}else if(c>a&&c>b){
				e[i].xid=3;
				if(b>a){
					e[i].yid=2;
					e[i].y = b;
				}else{
					e[i].y=a;
					e[i].yid=1;
				}
			}
		}
		sort(e+1,e+1+n,cmp);
		int sum[5]={0,0,0,0,0};
		for(int i=1;i<=n;i++){
			int now=e[i].xid;
			if(sum[now]<n/2){
				sum[now]++;
			}else{
				sum[e[i].yid]++;
				ans+=e[i].y;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
