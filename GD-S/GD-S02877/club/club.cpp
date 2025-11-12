#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
using ll =long long;
struct node{
	ll a,b,c;
	friend bool operator<(node x,node y){
		return x.a-x.b>y.a-y.b;
	}
}a[N];
ll T,n,lim,ans,f[205][205][205];
void dfs(ll cur,ll ca,ll cb,ll cc,ll cnt){
	if(cur>n){
		ans=max(ans,cnt);
		return ;
	}
	if(ca<lim) dfs(cur+1,ca+1,cb,cc,cnt+a[cur].a);
	if(cb<lim) dfs(cur+1,ca,cb+1,cc,cnt+a[cur].b);
	if(cc<lim) dfs(cur+1,ca,cb,cc+1,cnt+a[cur].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n,lim=n/2,ans=0;
		bool fl=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].c!=0) fl=0;
		}
		sort(a+1,a+n+1);
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}else if(fl){
			for(int i=1;i<=n/2;i++)   ans+=a[i].a;
			for(int i=n/2+1;i<=n;i++) ans+=a[i].b;
			cout<<ans<<endl; 
		}else{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
} 
/*
1
4
5 3 8
3 2 1
6 4 4
1 3 2
*/
