#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n;
ll ans;
priority_queue<int,vector<int>,greater<int> > Q1,Q2,Q3;
void solve(){
	ans=0;
	while(Q1.size()) Q1.pop();
	while(Q2.size()) Q2.pop();
	while(Q3.size()) Q3.pop();
	cin >> n;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin >> a >> b >> c;
		if(a>=b&&a>=c) Q1.push(a-max(b,c));
		else if(b>=a&&b>=c) Q2.push(b-max(a,c));
		else if(c>=a&&c>=b) Q3.push(c-max(a,b));
		ans+=max(max(a,b),c);
	}
	while((int)Q1.size()>n/2){
		ans-=Q1.top();
		Q1.pop();
	}
	while((int)Q2.size()>n/2){
		ans-=Q2.top();
		Q2.pop();
	}
	while((int)Q3.size()>n/2){
		ans-=Q3.top();
		Q3.pop();
	}
	cout << ans << "\n";
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
