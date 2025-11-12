#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6666666;
int t,a[N],x,y,n,m,ans;
int work(int x,int y){
	int c=1,d=1,e=1;
	for(int i=1;i<=x;i++)c*=i;
	for(int i=1;i<=y;i++)d*=i;
	for(int i=1;i<=x-y;i++)e*=i;
	return c/(d*e);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=2)cout<<0;
	if(n==3){
		ans=a[1]+a[2]+a[3];
		if(ans>a[3]*2)cout<<1;
		else cout<<0;
	}
	else if(n>3){
		for(int i=1;i<=n;i++)ans+=work(n,i);
		cout<<ans;
	}
	return 0;
}
