#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[5005];
int n;
ll ans=0;
void f(int x,int mx,ll s,int b){
	if(x==n+1) {
		if(s>mx*2&&b>2) {
//			cout<<x<<" "<<mx<<" "<<s<<" "<<b<<endl;
			ans=(ans+1)%998244353;
		}
		return ;
	}
	f(x+1,max(mx,a[x]),s+a[x],b+1);
	f(x+1,mx,s,b);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f(1,-1,0,0);
	cout<<ans;
	return 0;
}