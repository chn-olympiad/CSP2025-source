#include<bits/stdc++.h>
using namespace std;
#define fio(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define tio() freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define cio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using ll=long long;
using pii=pair<int,int>;
const int N=1e5+10; 
int T;
int n;
int cnt[4];
struct node{
	int b[4]; 
	int gmc(int id){
		return b[id]-b[1];
	}
	int gmcid(){
		if(b[2]-b[1]>b[3]-b[1])return 2;
		return 3;
	}
};
ll ans;
node a[N];
bool vis[N];
priority_queue<pair<int,pii> >q;
int main(){
//	tio();
	fio("club");
	cio();
	cin>>T;
	while(T--){
		cin>>n;
		ans=0ll;
		cnt[2]=cnt[3]=0;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;++i){
			cin>>a[i].b[1]>>a[i].b[2]>>a[i].b[3];
			ans+=a[i].b[1];
		}
		sort(a+1,a+1+n,[](node x,node y)->bool{return max(x.gmc(2),x.gmc(3))>max(y.gmc(2),y.gmc(3));});
		for(int i=1;i<=n/2;++i){
			ans+=max(a[i].gmc(2),a[i].gmc(3));
			++cnt[a[i].gmcid()];
		}
		while(!q.empty()){
			q.pop();
		}
		for(int i=n/2+1;i<=n;++i){
			q.push({a[i].gmc(2),{2,i}});
			q.push({a[i].gmc(3),{3,i}});
		}
		while(!q.empty()&&(cnt[2]<n/2||cnt[3]<n/2)){
			int v=q.top().first;
			pair<int,int> now=q.top().second;q.pop();
			if(v<=0)break;
			if(vis[now.second])continue;
			if(cnt[now.first]<n/2){
				++cnt[now.first];
				ans+=v;
				vis[now.second]=1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
1
4
1 2 3
3 1 2
4 2 1
1 3 4

*/
