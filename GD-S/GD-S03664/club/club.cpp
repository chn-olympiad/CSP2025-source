#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
struct Node{
	ll a,b,c,d,op;
}a[N];
ll T,n;
bool cmp(Node x,Node y){
	return x.d<y.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ll cnt1=0,cnt2=0,cnt3=0,res=0,op=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			ll ma=max(a[i].a,max(a[i].b,a[i].c));
			ll mi=min(a[i].a,min(a[i].b,a[i].c));
			a[i].d=2*ma+mi-a[i].a-a[i].b-a[i].c;
			if(ma==a[i].a) cnt1++,op=1;
			else if(ma==a[i].b) cnt2++,op=2;
			else cnt3++,op=3;
			a[i].op=op; res+=ma;
		}
		ll cnt=max(cnt1,max(cnt2,cnt3));
		if(cnt<=n/2){
			cout<<res<<"\n";
			continue;
		}
		sort(a+1,a+1+n,cmp);
		if(cnt1==cnt) op=1;
		else if(cnt2==cnt) op=2;
		else op=3;
		for(int i=1,j=1;i<=n && j<=cnt-(n/2);i++){
			if(a[i].op!=op) continue;
			res-=a[i].d;
			j++;
		}
		cout<<res<<"\n";
	}
	return 0;
}
