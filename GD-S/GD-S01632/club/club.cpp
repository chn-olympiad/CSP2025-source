#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,cnt[4];
struct node{
	int x,y,z,mx,mi,sc,si;
}a[N];
bool cmp(node x,node y){
	return x.mx>y.mx;
}
void solve(){
	cin>>n;
	priority_queue<int,vector<int>,greater<int> > q[4];
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		int mx=max({x,y,z});
		a[i]={x,y,z,mx,0,0,0};
		if(mx==x) a[i].sc=max(y,z),a[i].mi=1,a[i].si=(a[i].sc==y?2:3);
		else if(mx==y) a[i].sc=max(x,z),a[i].mi=2,a[i].si=(a[i].sc==x?1:3);
		else a[i].sc=max(x,y),a[i].mi=3,a[i].si=(a[i].sc==x?1:2);
//		cout<<a[i].mx<<' '<<a[i].sc<<'\n';
	} 
//	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++) cout<<a[i].mx<<' '<<a[i].sc<<'\n';
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i].mx;
		q[a[i].mi].push(a[i].mx-a[i].sc);
	}
	int k=0;
	if(q[1].size()>n/2) k=1;
	else if(q[2].size()>n/2) k=2;
	else k=3;
	while(q[k].size()>n/2){
		int val=q[k].top();
		q[k].pop();
		ans-=val;
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
