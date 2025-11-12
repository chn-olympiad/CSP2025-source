#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1000;
int n,m;
int a[maxn],s,pos;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	s=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++)
		if(a[i]==s)
			pos=i;
	if(pos%n==0){
		if((pos/n)&1){
			cout<<pos/n<<' '<<n;
		}else {
			cout<<pos/n<<' '<<1;
		}
	}
	else {
		int x=pos/n+1; 
		if(x&1){
			cout<<x<<' '<<pos-(x-1)*n+1;
		}else {
			cout<<x<<' '<<x*n-pos+1;
		}
	}
	return 0;
}

