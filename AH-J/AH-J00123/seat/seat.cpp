#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> p;
ll n,m,cnt,s;
p a[105];
bool cmp(p x,p y){
	return x.first>y.first;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) for(ll j=1;j<=m;j++){
		cin>>a[++cnt].first;
		a[cnt].second=cnt;
	}
	sort(a+1,a+cnt+1,cmp);
	for(ll i=1;i<=cnt;i++){
		if(a[i].second==1){
			s=i;
			break;
		}
	}
	//cout<<s<<endl;
	cout<<(s-1)/n+1<<" ";
	if(((s-1)/n+1)&1) cout<<(s-1)%n+1;
	else cout<<n-(s-1)%n;
	return 0; 
}
