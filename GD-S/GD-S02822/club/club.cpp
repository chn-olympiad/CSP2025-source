#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node{
	pair<int,int> u[4];
	int price;
	//first -> value
	//second -> id
}p[N];
struct club{
	int price,pos;
	bool operator<(const club other) const{
		return price>other.price;
	} 
};
ll T,ans;
int n,sum[4];
bool cmp(pair<int,int> nx,pair<int,int> ny){
	return nx.first>ny.first;
}
void solve(){
	cin>>n;
	ans=0;
	priority_queue<club> cnt[4];
//	while(!cnt[1].empty()) cnt[1].pop();
//	while(!cnt[2].empty()) cnt[2].pop();
//	while(!cnt[3].empty()) cnt[3].pop();
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++){
		cin>>p[i].u[1].first>>p[i].u[2].first>>p[i].u[3].first;
		p[i].u[1].second=1;
		p[i].u[2].second=2;
		p[i].u[3].second=3;
		sort(p[i].u+1,p[i].u+4,cmp);
		p[i].price=p[i].u[1].first-p[i].u[2].first;
//		p[i].price[1]=p[i].u[2].first-p[i].u[3].first;
		int tmp=p[i].u[1].second,
			cur=cnt[p[i].u[1].second].top().pos;
		//tmp为当前这一个最大值所对应的部门编号
		if(sum[tmp]>=(n>>1)){
			int pri=cnt[tmp].top().price;
			if(p[i].u[1].first<p[i].u[2].first+pri){
				sum[p[i].u[2].second]++;
				cnt[p[i].u[2].second].push({p[i].price,i});
				ans+=p[i].u[2].first;
			}
			else{
				ans-=pri;
				sum[p[cur].u[2].second]++;
				cnt[tmp].pop();
				cnt[tmp].push({p[i].price,i});
				ans+=p[i].u[1].first;
			}
		}
		else{
			ans+=p[i].u[1].first;
			sum[p[i].u[1].second]++;
			cnt[tmp].push({p[i].price,i});
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
