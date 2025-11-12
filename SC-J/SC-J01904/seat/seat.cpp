#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll n,m,num,a[105],pos;
bool cmp(ll x,ll y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>a[i];
	num=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;++i){
		if(a[i]==num){
			pos=i;
			break;
		}
	}
	if(pos%n==0){
		cout<<pos/n<<' ';
		if((pos/n)&1) cout<<n;
		else cout<<1;
	}
	else{
		cout<<pos/n+1<<' ';
		if((pos/n)&1) cout<<n-pos%n+1;
		else cout<<pos%n;
	}
	return 0;
}