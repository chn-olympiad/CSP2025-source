#include<bits/stdc++.h>
using namespace std;
long long n,m,t,xx,cnt,yy,ans,a[110];
void solve(){
	cin>>n>>m;
	t=n*m;
	for(long long i=1;i<=t;i++) cin>>a[i];
	xx=a[1];
	sort(a+1,a+t+1);
	for(long long i=t;i>=1;i--){
		if(a[i]==xx) ans=t-i+1;
	}
	if(ans%n==0) cnt=ans/n;
	else cnt=(ans/n)+1;
	if(ans%n==0) yy=n;
	else yy=ans%n;
	if(cnt%2==0) cout<<cnt<<' '<<n-yy<<endl;
	else cout<<cnt<<' '<<yy<<endl;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) solve();
	return 0;
}
