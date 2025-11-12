#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[1000086],x[1000086],cnt,ans;
ll a0,a1; 
struct Node{
	ll st,en;
}num[1000086];
bool cmp(Node aa,Node bb){
	return aa.st<bb.st;
}
void bfs(){
	queue<ll> p,s;
	p.push(0),s.push(0);
	while(!p.empty()){
		ll enx=p.front(),sx=s.front();
		ans=max(ans,sx);
		p.pop(),s.pop();
		for(ll i=1;i<=cnt;i++){
			if(num[i].st>enx){
				p.push(num[i].en),s.push(sx+1);
			}
		}
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) a0++;
		if(a[i]==1) a1++;
		x[i]=a[i]^x[i-1];
	}
	if(a0+a1==n){
		if(m==0) cout<<a0;
		else if(m==1) cout<<a1;
		else cout<<0;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			ll t=x[i-1]^x[j];
			if(t==m){
				++cnt,num[cnt].st=i,num[cnt].en=j;
			}
		}
	}
	bfs();
	cout<<ans;
	return 0;
}
