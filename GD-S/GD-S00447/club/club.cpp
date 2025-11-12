#include<bits/stdc++.h>
#define d first
#define idx second
using namespace std;
int T,n,a[100005][4],ans;
int maxx[100005];
/*
容易证明，无论如何从最高的一个替换出去，
都不会使得被换出去的填至n/2 
*/ 
int cnt[4];
//struct node{
//	int idx,d;
//	bool operator <(const node q2){
//		return idx<q2.idx;
//	}
//};
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i = 1 ; i <= n ; ++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				maxx[i]=1;
				++cnt[1];
				q[1].push(make_pair(a[i][1]-max(a[i][2],a[i][3]),i));
				ans+=a[i][1];
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				maxx[i]=2;
				++cnt[2];
				q[2].push(make_pair(a[i][2]-max(a[i][1],a[i][3]),i));
				ans+=a[i][2];
			}else{
				maxx[i]=3;
				++cnt[3];
				q[3].push(make_pair(a[i][3]-max(a[i][1],a[i][2]),i));
				ans+=a[i][3];
			}
		}//贪心地选择最高的	 
		if(cnt[1]>n/2){
			while(cnt[1]>n/2){
				//重复，找到fst[1]的最小值，然后把他扔出去
				//明显，应当使用优先队列
				pair<int,int> cur=q[1].top();
				q[1].pop();
				--cnt[1];
				ans-=cur.d;
			}
		}else if(cnt[2]>n/2){
			while(cnt[2]>n/2){
				pair<int,int> cur=q[2].top();
				q[2].pop();
				--cnt[2];
				ans-=cur.d;
			}
		}else{
			while(cnt[3]>n/2){
				pair<int,int> cur=q[3].top();
				q[3].pop();
				--cnt[3];
				ans-=cur.d;
			}
		}
		cout<<ans<<"\n";
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		while(!q[3].empty())q[3].pop();
	}
	cout<<flush;
	return 0;
}

