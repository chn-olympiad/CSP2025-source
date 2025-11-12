#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long ull;
const int N=100005;
int t,n,lim,a[N][5],ans=0;
priority_queue<P,vector<P>,greater<P> >q;//如果堆中某个元素换掉造成的损失
void work(int id){
	while(q.size())q.pop();
	int cnt[5]{},delta=0,sum=0;
	for(int i=1;i<=n;++i){
		int c1=a[i][id],c2=0,flag=0;
		if(id==1){
			if(a[i][2]==a[i][3])flag=0,c2=a[i][2];
			else if(a[i][2]>a[i][3])flag=2,c2=a[i][2];
			else flag=3,c2=a[i][3];
		} else if(id==2){
			if(a[i][1]==a[i][3])flag=0,c2=a[i][1];
			else if(a[i][1]>a[i][3])flag=1,c2=a[i][1];
			else flag=3,c2=a[i][3];
		} else if(id==3){
			if(a[i][1]==a[i][2])flag=0,c2=a[i][1];
			else if(a[i][1]>a[i][2])flag=1,c2=a[i][1];
			else flag=2,c2=a[i][2];
		}
		if(c1>=c2){
			if(q.size()<lim)q.push({c1-c2,flag}),sum+=c1;
			else {
				int u=q.top().first;
				if(u>c1-c2){
					++cnt[flag];
					sum+=c2;
					continue;
				}
				else {
					int id1=q.top().second;
					q.pop(),++cnt[id1];
					sum+=(c1-u);
					q.push({c1-c2,flag});
				}
			}
		} else {
			++cnt[flag];
			sum+=c2;
		}
		// cout<<sum<<'\n';
	}
	int x=0;
	if(id==1)x=max(cnt[2],cnt[3]);
	if(id==2)x=max(cnt[1],cnt[3]);
	if(id==3)x=max(cnt[1],cnt[2]);
	if(x>lim)return ;
	ans=max(ans,sum);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int ttt;cin>>ttt;
	while(ttt--){
		ans=0;
		cin>>n;lim=n/2;
		for(int i=1;i<=n;++i)cin>>a[i][1]>>a[i][2]>>a[i][3];
		work(1),work(2),work(3);
		cout<<ans<<'\n';
	}
	return 0;
}