#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define N 100005
int t,n;
struct f{
	int a;
	int b;
	int c;
}d[N];
priority_queue<int,vector<int>,greater<int> >pq1;
priority_queue<int,vector<int>,greater<int> >pq2;
priority_queue<int,vector<int>,greater<int> >pq3;
int f[N];
void solve(){
	while(pq1.size()) pq1.pop();
	while(pq2.size()) pq2.pop();
	while(pq3.size()) pq3.pop();
	cin>>n;
	int k=n/2;
	for(int i=1;i<=n;i++){
		cin>>d[i].a>>d[i].b>>d[i].c;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		int mx=max(max(d[i].a,d[i].b),d[i].c);
		int mi=min(min(d[i].a,d[i].b),d[i].c);
		int md=d[i].a+d[i].b+d[i].c-mi-mx;
		if(mx==d[i].a) pq1.push(mx-md);
		if(mx==d[i].b) pq2.push(mx-md);
		if(mx==d[i].c) pq3.push(mx-md);
		ans+=mx;
		if(pq1.size()>k){
			ans-=pq1.top();
			pq1.pop();
		}
		if(pq2.size()>k){
			ans-=pq2.top();
			pq2.pop();
		}
		if(pq3.size()>k){
			ans-=pq3.top();
			pq3.pop();
		}
	}
	cout<<ans<<endl;
}
void doing(){
	cin>>t;
	while(t--) solve();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	doing();
	return 0;
}
