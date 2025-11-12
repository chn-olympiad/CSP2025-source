#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,m,ans;
int dp[N][4];
int bj[N];
bool fl[N],fl1[N];
struct node{
	int x,y,z;
}a[N];
struct node1{
	int x,y,z,id;
	bool operator>(const node1 &p)const{
		return x-y>p.x-p.y;
	}
};
struct node2{
	int x,y,z,id;
	bool operator>(const node2 &p)const{
		return y-z>p.y-p.z;
	}
};
struct node3{
	int x,y,z,id,in;
	bool operator<(const node3 &p)const{
		return x<p.x;
	}
};
void dfs(int x,int sum,int cnt1,int cnt2,int cnt3){
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(cnt1<n/2) dfs(x+1,sum+a[x].x,cnt1+1,cnt2,cnt3);
	if(cnt2<n/2) dfs(x+1,sum+a[x].y,cnt1,cnt2+1,cnt3);
	if(cnt3<n/2) dfs(x+1,sum+a[x].z,cnt1,cnt2,cnt3+1);
}
bool cmp(node x,node y){
	return x.x>y.x;
}
signed main(){
	freopen("club5.in","r",stdin);
	scanf("%lld",&T);
	while(T--){
		priority_queue<node1,vector<node1>,greater<node1> > q1;
		priority_queue<node2,vector<node2>,greater<node2> > q2,q3;
//		priority_queue<node3,vector<node3>,less<node3> > q1;
		scanf("%lld",&n);
		int h=n/2;bool bj1=0,bj2=0;
		int cnt[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y) bj1=1;
			if(a[i].z) bj2=1;
			q1.push({a[i].x,a[i].y,a[i].z,i});
			q1.push({a[i].x,a[i].z,a[i].y,i});
			ans+=a[i].x;
		}
		if(n<=10){
			dfs(0,0,0,0,0);
			printf("%lld\n",ans);
			ans=0;
			continue;
		}
		if(!bj1&&!bj2){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=h;i++){
				ans+=a[i].x;
			}
			printf("%lld\n",ans);
			ans=0;
			continue;
		}
		int maxn=0;
		for(int i=1;i<=n;i++){
			dp[i][0]=maxn+a[i].x;
			dp[i][1]=maxn+a[i].y;
			dp[i][2]=maxn+a[i].z;
			maxn=max(dp[i][0],max(dp[i][1],dp[i][2]));
		}
//		while(q1.size()){
//			node3 u=q1.top();
//			q1.pop();
//			if((bj[u.id]&&bj[u.id]!=u.x)||cnt[u.in]==h) continue;
//			ans+=u.x;
//			bj[u.id]=u.x;
//			cnt[u.in]++;
//		}
//		while(q1.size()&&(q1.top().x-q1.top().y<=0||q1.size()>h)){
//			node1 u=q1.top();
//			q1.pop();
//			q1.push({u.y,u.z,u.z,u.id});
//			ans=ans-u.x+u.y;
//			if(q2.size()>h){
//				node2 u=q2.top();
//				q2.pop();
//				q3.push({u.x,u.y,u.z,u.id});
//				ans=ans-u.y+u.z;
//			} 
//		}
		printf("%lld\n",maxn);
//		printf("%lld\n",max(maxn,ans));
		ans=0;
	}
	return 0;
}
