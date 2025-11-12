#include<bits/stdc++.h> 
#define int long long
using namespace std;
priority_queue<int,vector<int>,greater<int>>a1;
priority_queue<int,vector<int>,greater<int>>b1;
priority_queue<int,vector<int>,greater<int>>c1;
void solve(){
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,c,b;
		cin>>a>>b>>c;
		ans+=max(a,max(b,c));
		if(a>b&&a>c)
			a1.push(a-max(b,c));
		if(b>a&&b>c)
			b1.push(b-max(a,c));
		if(c>a&&c>b)
			c1.push(c-max(a,b));
	}
	while(a1.size()>n/2){
		ans-=a1.top();
		a1.pop();
	}
	while(b1.size()>n/2){
		ans-=b1.top();
		b1.pop();
	}
	while(c1.size()>n/2){
		ans-=c1.top();
		c1.pop();
	}
	while(!a1.empty())a1.pop();
	while(!b1.empty())b1.pop();
	while(!c1.empty())c1.pop();
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
