#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int a[200010][4];
int tot[4];
struct node{
	int val;
	int id;
};
bool operator < (node a,node b){
	return a.val<b.val;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		memset(a,0,sizeof(a));
		memset(tot,0,sizeof(tot));
		priority_queue<int,vector<int>,greater<int> > q1[4];
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++){
			priority_queue<node> q;
			q.push({a[i][1],1});
			q.push({a[i][2],2});
			q.push({a[i][3],3});
			int h=q.top().val,hi=q.top().id;
			q.pop();
			int h2=h-q.top().val;
			q1[hi].push(h2);
			ans+=h;
			tot[hi]++;
		}
		if(tot[1]>n/2){
			while(tot[1]-n/2>0){
				ans-=q1[1].top();
				q1[1].pop();
				tot[1]--;
			}
		}
		if(tot[2]>n/2){
			while(tot[2]-n/2>0){
				ans-=q1[2].top();
				q1[2].pop();
				tot[2]--;
			}
		}
		if(tot[3]>n/2){
			while(tot[3]-n/2>0){
				ans-=q1[3].top();
				q1[3].pop();
				tot[3]--;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}