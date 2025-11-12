#include <bits/stdc++.h>
const int N=1e5+10;
using namespace std;
typedef long long ll;
int t,n;
int cnt[5];
ll ans;
struct node{
	int a[5];
	bool operator<(const node& other) const{
		return (a[1]+a[2]+a[3]-max({a[1],a[2],a[3]})-min({a[1],a[2],a[3]}))<(other.a[1]+other.a[2]+other.a[3]-max({other.a[1],other.a[2],other.a[3]})-min({other.a[1],other.a[2],other.a[3]}));
	}
} x[N];
priority_queue<node> q[5];
int mymax(node x){
	return max({x.a[1],x.a[2],x.a[3]});
}
int mymid(node x){
	return x.a[1]+x.a[2]+x.a[3]-max({x.a[1],x.a[2],x.a[3]})-min({x.a[1],x.a[2],x.a[3]});
}
bool cmp1(node x,node y){
	return max({x.a[1],x.a[2],x.a[3]})==max({y.a[1],y.a[2],y.a[3]})?mymid(x)>mymid(y):max({x.a[1],x.a[2],x.a[3]})>max({y.a[1],y.a[2],y.a[3]});
}
void init(){
	ans=0;
	cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=3;i++)
		while(!q[i].empty())
			q[i].pop();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&x[i].a[1],&x[i].a[2],&x[i].a[3]);
		sort(x+1,x+n+1,cmp1);
		for(int i=1;i<=n;i++){
			int mx=mymax(x[i]),flag=0;
			for(int j=1;j<=3;j++)
				if(x[i].a[j]==mx){
					if(cnt[j]<n/2){
						ans+=x[i].a[j],cnt[j]++,q[j].push(x[i]);
						flag=1;
						break;
					}else{
						auto t=q[j].top();
						if(mx+mymid(t)>=mymax(t)){
							ans+=(mx+mymid(t)-mymax(t));
							for(int k=1;k<=3;k++)
								if(cnt[k]<n/2&&t.a[k]==mymid(t)){
									cnt[k]++,q[k].push(t);
									break;
								}
							q[j].pop();
							q[j].push(x[i]);
							flag=1;
							break;
						}
					}
				}
			if(!flag){
				for(int j=1;j<=3;j++)
					if(cnt[j]<n/2&&x[i].a[j]==mymid(x[i])){
						ans+=x[i].a[j],cnt[j]++,q[j].push(x[i]);
						break;
					}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
