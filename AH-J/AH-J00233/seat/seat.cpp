#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a,o,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>o;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>o)ans++;
	}
	//cout<<ans<<' ';
	if(((ans/n)%2)==0)cout<<ans/n+1<<' '<<ans%n+1;
	if(((ans/n)%2)!=0)cout<<ans/n+1<<' '<<n-(ans%n);
	return 0;
}
