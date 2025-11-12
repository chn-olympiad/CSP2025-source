#include<bits/stdc++.h>
using namespace std;
long long p[5005];
long long e=998244353;
long long a;
long long ans=0;
void f(long long x,long long w,long long r,long long t){
	if(x>=3){
	if(t>a) return;
	if(w*2<r) {
		ans++;
	}}
	for(int i=t+1;i<=a;i++){
		f(x+1,max(w,p[i]),r+p[i],i);
	}
	ans%=e;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>p[i];
	}
	if(a==3){
		int ll=max(p[0],p[1]);
		ll=max(p[1],p[2]);
		int ee=p[0]+p[1]+p[2];
		if(ll*2<ee) cout<<1;
		else cout<<0;
		return 0;
	}
	f(0,0,0,0);
	cout<<ans%e;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
