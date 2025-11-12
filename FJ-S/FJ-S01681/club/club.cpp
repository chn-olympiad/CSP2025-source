#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N = 1e5 + 5;
struct node{
	ll a,b,c;
}a[N];
int Q = 0;
ll T,n;
bool ret(node a,node b){
	return a.a<b.a;
}
void sf(){
	cin>>n;
	for(int i=n;i>=1;i--){
		ll maxn=-1;
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	sort(a+1,a+1+n,ret);
	return; 
}

void cl(){
	ll ans=0;
	ll ai=0,bi=0,ci=0;
	for(int i=1;i<=n;i++){
		if(a[i].a>a[i].b&&a[i].a>a[i].c&&ai<n/2){
			ans+=a[i].a;
			ai++;
		}
		else if(a[i].b>a[i].c&&bi<n/2){
			ans+=a[i].b;
			bi++;
		}
		else {
			ans+=a[i].c;
		}
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		sf();
		cl();
	}
	return ( Q ^ Q );
}
