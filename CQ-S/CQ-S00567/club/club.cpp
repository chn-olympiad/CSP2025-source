#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int maxn=200010;
int T,n,a[maxn],b[maxn],c[maxn];
int cnt1,cnt2,cnt3,cx[maxn];
int d[maxn],ans;
priority_queue<int>st1,st2,st3;
void solve(){
	cin>>n;
	ans=0;
	while(!st1.empty())st1.pop();
	while(!st2.empty())st2.pop();
	while(!st3.empty())st3.pop();
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		int maxx=max({a[i],b[i],c[i]});
		int minx=min({a[i],b[i],c[i]});
		d[i]=2*maxx+minx-a[i]-b[i]-c[i];
		if(a[i]==maxx)cx[i]=1,st1.push(-d[i]);
		else if(b[i]==maxx)cx[i]=2,st2.push(-d[i]);
		else cx[i]=3,st3.push(-d[i]);
		ans+=maxx;
	}
	while((int)st1.size()>n/2){
		ans+=st1.top();
		st1.pop();
	}
	while((int)st2.size()>n/2){
		ans+=st2.top();
		st2.pop();
	}	
	while((int)st3.size()>n/2){
		ans+=st3.top();
		st3.pop();
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)solve();
	return 0;
}
