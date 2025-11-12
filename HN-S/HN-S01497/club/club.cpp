#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
ll ans;
struct club{
	int id,w;
};
struct compare{
	bool operator()(int x,int y){
		return x>y;
	}
};
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		int n;
		cin>>n;
		priority_queue<int,vector<int>,compare>q[5];
		club x,y,z;
		for(int i=1;i<=n;i++){
			cin>>x.w>>y.w>>z.w;
			x.id=1,y.id=2,z.id=3;
			if(x.w<y.w)
			  swap(x,y);
			if(y.w<z.w)
			  swap(y,z);
			if(x.w<y.w)
			  swap(x,y);
			ans+=x.w;
			q[x.id].push(x.w-y.w);
			if(q[x.id].size()>n/2){
				int t=q[x.id].top();
//				cout<<q[x.id].top()<<' ';
				q[x.id].pop();
//				cout<<q[x.id].top()<<'\n';
				ans-=t;
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
