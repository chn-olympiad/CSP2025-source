#include<bits/stdc++.h>
using namespace std;
#define N 100005
typedef long long ll;
typedef pair<int,int> pii;
inline int read(){
	register int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if (ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int T;
int n;
int a[N][4];
int ans;
bool flag=true;
struct node{
	int a,b;
	int ra,rb;
}f[N];
struct node2{
	int ans,id,a,b,c;
};
bool cmp(node a,node b){
	return (a.a==b.a?a.b>b.b:a.a>b.a);
}
inline void solve2(){
	for(int i=1;i<=n;i++)a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
	queue<node2> pq;
	pq.push({0,1,0,0,0});
	while(!pq.empty()){
		node2 u=pq.front();pq.pop();
		if (u.a>(n>>1)||u.b>(n>>1)||u.c>(n>>1))continue;
		if (u.id>n){
			ans=max(ans,u.ans);
			continue;
		}
		pq.push({u.ans+a[u.id][1],u.id+1,u.a+1,u.b,u.c});
		pq.push({u.ans+a[u.id][2],u.id+1,u.a,u.b+1,u.c});
		pq.push({u.ans+a[u.id][3],u.id+1,u.a,u.b,u.c+1});
	}
	cout<<ans<<'\n';
}
inline void solve3(){
	vector<int> vec;
	for(int i=1;i<=n;i++)vec.push_back(a[i][1]);
	sort(vec.begin(),vec.end());
	for(int i=n-1;i>=n-(n>>1);i--)ans+=vec[i];
	cout<<ans<<'\n';
}
inline void solve(){
	priority_queue<pii,vector<pii>,greater<pii>> q[4];
	memset(f,0,sizeof(f));
	n=read();ans=0;flag=true;
	if (n<=5000){
		solve2();
		return;
	}
	for(int i=1;i<=n;i++){
		a[i][1]=read();
		a[i][2]=read();
		a[i][3]=read();
		if (a[i][2]||a[i][3])flag=false;
		vector<pii> vec;
		vec.push_back({a[i][1],1});
		vec.push_back({a[i][2],2});
		vec.push_back({a[i][3],3});
		sort(vec.begin(),vec.end());
		f[i]={vec[2].first,vec[1].first,vec[2].second,vec[1].second};
	}
	if(flag){
		solve3();
		return;
	}
	for(int i=1;i<=n;i++){
		if (q[f[i].ra].size()>=(n>>1)){
			ll lst=q[f[i].ra].top().first,lstid=q[f[i].ra].top().second;
			ll ans1=ans-lst+f[lstid].b+f[i].a;
			ll ans2=ans+f[i].b;
			if (ans1>ans2){
				ans-=lst;
				ans+=f[lstid].b;
				q[f[lstid].rb].push({f[lstid].b,lstid});
				q[f[i].ra].pop();
				q[f[i].ra].push({f[i].a,i});
				ans+=f[i].a;
			}
			else{
				ans+=f[i].b;
				q[f[i].rb].push({f[i].b,i});
			}
		}
		else{
			ans+=f[i].a;
			q[f[i].ra].push({f[i].a,i});
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)solve();
	return 0;
}
