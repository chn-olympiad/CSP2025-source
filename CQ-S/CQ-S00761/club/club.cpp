#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e5+5;
int t,n,a[N][4],ans;
vector<int>box[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		box[1].clear();
		box[2].clear();
		box[3].clear();
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int maxn=max({a[i][1],a[i][2],a[i][3]});
			if(a[i][1]==maxn){
				box[1].push_back(i);
			}else if(a[i][2]==maxn){
				box[2].push_back(i);
			}else{
				box[3].push_back(i);
			}
			ans+=maxn;
		}
		if(box[1].size()>n/2){
			int num=box[1].size()-n/2;
			priority_queue<int>q;
			for(auto i:box[1]){
				q.push(max(a[i][2],a[i][3])-a[i][1]);
			}
			while(num--){
				ans+=q.top();
				q.pop();
			}
		}else if(box[2].size()>n/2){
			int num=box[2].size()-n/2;
			priority_queue<int>q;
			for(auto i:box[2]){
				q.push(max(a[i][1],a[i][3])-a[i][2]);
			}
			while(num--){
				ans+=q.top();
				q.pop();
			}
		}else if(box[3].size()>n/2){
			int num=box[3].size()-n/2;
			priority_queue<int>q;
			for(auto i:box[3]){
				q.push(max(a[i][1],a[i][2])-a[i][3]);
			}
			while(num--){
				ans+=q.top();
				q.pop();
			}
		}
		cout<<ans<<'\n';
	}
}
