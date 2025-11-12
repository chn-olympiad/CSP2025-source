#include<bits/stdc++.h>
using namespace std;
unsigned long long n,a[25],maxx,ans,l;
void f(int x,int s,int k){
	if(x==k){
		if(s>2*maxx) ans++;
		return;
	}
	for(int i=x+1;i<=n;i++){
		int y=maxx;
		if(a[i]>maxx) maxx=a[i];
		f(i,s+a[i],k);
		maxx=y;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++) f(0,0,i);
	cout<<ans%998244353;
	return 0;
}
