#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool stt;
const int N=1e4+10;
const int M=1e6+10;
int n,m,k,cnt;
ll ans;
struct node{
	int x,y,z;
}h[M],g[M];
bool cmp(node x,node y){
	return x.z<y.z;
}
int val[12];
struct tp{
	int val,id;
}a[12][N];
int f[N];
int find(int x){
	return (f[x]==x?x:f[x]=find(f[x]));
}
bool edd;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>h[i].x>>h[i].y>>h[i].z;
	sort(h+1,h+1+m,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int x=find(h[i].x),y=find(h[i].y);
		if(x==y) continue;
		f[y]=x;
		g[++cnt]=h[i];
		ans+=h[i].z;
	}
	m=cnt;
	for(int i=1;i<=m;i++) h[i]=g[i];
	for(int i=1;i<=k;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++) cin>>a[i][j].val,a[i][j].id=j;
		sort(a[i]+1,a[i]+1+n,[&](tp x,tp y){return x.val<y.val;});
	}
//	cout<<ans<<"\n";
//	return 0;
	int lim=(1<<k);
	for(int s=1;s<lim;s++){
//		cout<<s<<"\n";
		for(int i=1;i<=n+k;i++) f[i]=i;
		ll sum=0;cnt=0;
		priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> q;
		for(int p=1;p<=k;p++){
			if((s>>(p-1))&1){
				sum+=val[p];
				q.push({a[p][1].val,{p+n,1}});
			}
		}
		q.push({h[1].z,{0,1}});
		while(!q.empty()){
			if(sum>ans) break;
			pair<int,pair<int,int>> u=q.top();q.pop();
			int val=u.first,pos=u.second.first,ip=u.second.second;
//			cout<<pos<<" "<<ip<<" ";
			if(pos==0){
				int x=find(h[ip].x),y=find(h[ip].y);
				if(x!=y) f[x]=y,sum+=val;
				ip++;
				if(ip<=m) q.push({h[ip].z,{0,ip}});
			}else{
				int x=find(pos),y=find(a[pos-n][ip].id);
				if(x!=y) f[x]=y,sum+=val;
				ip++;
				if(ip<=n) q.push({a[pos-n][ip].val,{pos,ip}});
			}
		}
//		cout<<sum<<"\n";
		ans=min(ans,sum);
	}
	cout<<ans<<"\n";
	cerr<<(&edd-&stt)/1024.0/1024<<"\n";
	return 0;
}
