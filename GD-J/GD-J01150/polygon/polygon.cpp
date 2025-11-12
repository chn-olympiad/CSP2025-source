#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int mod=998244353;
const int N=5005;
int n,a[N],ans;
priority_queue<int,vector<int>,greater<int>>q;
vector<int>g;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a,a+1+n);
	q.push(a[1]+a[2]);
	for(int i=3;i<=n;++i){
		while(!q.empty()){
			if(q.top()>a[i]){
				ans+=q.size();
				ans%=mod;
				break;
			}
			g.push_back(q.top()+a[i]);
			q.pop();
		}
		while(!q.empty()){
			g.push_back(q.top());
			g.push_back(q.top()+a[i]);
			q.pop();
		}
		int l=g.size();
		for(int j=0;j<l;++j){
			q.push(g[j]);
		}
		for(int j=1;j<i;++j){
			q.push(a[j]+a[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
