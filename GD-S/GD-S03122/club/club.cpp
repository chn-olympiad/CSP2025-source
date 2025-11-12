#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,a[N][4],ans,dis[N][4];
int b[N];
struct node{
	int sum,cnt1,cnt2,cnt3;
	int dep,id;
	bool operator<(const node &d) const {
		return sum>d.sum;
	}
}tmp,now;
priority_queue<node> q;
void solve(){
	memset(dis,~0x3f3f3f3f,sizeof(dis));
	while(!q.empty()) q.pop();
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld %lld %lld",&a[i][1],&a[i][2],&a[i][3]);
	bool flag1=1,flag2=1;
	ans=0;
	for(int i=1;i<=n;i++){
		if(a[i][3]!=n) flag1=flag2=0;
		else if(a[i][2]!=n) flag2=0;
	}
	if(flag2){
		for(int i=1;i<=n;i++){
			b[i]=a[i][1];
		}
		sort(b+1,b+1+n,greater<int>() );
		for(int i=1;i<=n/2;i++){
			ans+=b[i];
		}
		printf("%lld\n",ans);
		return;
	} 
	else if(flag1){
		priority_queue<pair<int,int> > pq;
		while(!pq.empty()) pq.pop();
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]){
				cnt1++;
				pq.push({a[i][2]-a[i][1],0});
			}
			else {
				cnt2++;
				pq.push({a[i][1]-a[i][2],1});
			}
			ans+=max(a[i][1],a[i][2]);
		}
		while(cnt1>(n/2)){
			pair<int,int> no=pq.top();
			pq.pop();
			if(no.second==0){
				ans+=no.first;
				cnt1--;
				cnt2++;
			}
		}
		while(cnt2>(n/2)){
			pair<int,int> no=pq.top();
			pq.pop();
			if(no.second==1){
				ans+=no.first;
				cnt2--;
				cnt1++;
			}
		}
		printf("%lld\n",ans);
		return;
	}
	if(n<=10){
		tmp.sum=a[1][1];
		tmp.cnt1=1,tmp.cnt2=0,tmp.cnt3=0;
		tmp.dep=1,tmp.id=1;
		q.push(tmp);
		tmp.sum=a[1][2];
		tmp.cnt1=0,tmp.cnt2=1,tmp.cnt3=0;
		tmp.dep=1,tmp.id=2;
		q.push(tmp);
		tmp.sum=a[1][3];
		tmp.cnt1=0,tmp.cnt2=0,tmp.cnt3=1;
		tmp.dep=1,tmp.id=3;
		q.push(tmp);
		dis[1][1]=a[1][1];
		dis[1][2]=a[1][2];
		dis[1][3]=a[1][3];
		while(!q.empty()){
			now=q.top();q.pop();
			if(now.dep==n) continue;
			if(now.cnt1+1<=(n/2)&&dis[now.dep+1][1]<=now.sum+a[now.dep+1][1]){
				dis[now.dep+1][1]=now.sum+a[now.dep+1][1];
				tmp=now;
				tmp.cnt1++;
				tmp.dep++;
				tmp.id=1;
				tmp.sum=dis[now.dep+1][1];
				q.push(tmp);
			}
			if(now.cnt2+1<=(n/2)&&dis[now.dep+1][2]<=now.sum+a[now.dep+1][2]){
				dis[now.dep+1][2]=now.sum+a[now.dep+1][2];
				tmp=now;
				tmp.cnt2++;
				tmp.dep++;
				tmp.id=2;
				tmp.sum=dis[now.dep+1][2];
				q.push(tmp);
			}
			if(now.cnt3+1<=(n/2)&&dis[now.dep+1][3]<=now.sum+a[now.dep+1][3]){
				dis[now.dep+1][3]=now.sum+a[now.dep+1][3];
				tmp=now;
				tmp.cnt3++;
				tmp.dep++;
				tmp.id=2;
				tmp.sum=dis[now.dep+1][3];
				q.push(tmp);
			}
		}
		printf("%lld\n",max({dis[n][1],dis[n][2],dis[n][3]}));
		return;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--) solve();
	return 0;
}

