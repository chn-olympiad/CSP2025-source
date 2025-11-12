#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define ull unsigned long long;
using namespace std;
/*
zhangchenge
*/
int n,m,a,b,fl,x,y;
void solve(){
	cin>>n>>m>>a;
	f(i,1,n*m-1){
		cin>>b;
		if(b<a&&fl==0){
			fl=1;
			x=(i+n-1)/n;
			if(x%2==1)y=(i%n==0?n:i%n);
			else y=n-(i%n==0?n:i%n)+1;
			cout<<x<<" "<<y; 
		}
	}if(fl==0){
		if(m&1)cout<<n<<" "<<m;
		else cout<<n<<" "<<1;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--)solve();
}
