#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans;
priority_queue<int> Q;
const int MOD=998244353;
queue<int> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	Q.push(0);
	for(int i=1;i<=n;i++){
		while(!Q.empty()){
			q.push(Q.top());
			q.push(Q.top()+a[i]);
			Q.pop();
		}
		while(!q.empty()){
			Q.push(q.front());
			q.pop();
		}
		while(!Q.empty()&&Q.top()>a[i]*2){
			q.push(Q.top());
			Q.pop();
			ans=(ans+1)%MOD;
		}
		while(!q.empty()){
			Q.push(q.front());
			q.pop();
		}
	}
	cout<<ans;
	return 0;
}