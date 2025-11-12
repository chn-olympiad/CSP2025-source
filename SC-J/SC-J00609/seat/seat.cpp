#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,inf=1e9+5;
int n,m,r,w;
int a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==r) w=n*m-i+1;
	}
//	cout<<w;
	if(w<=n){
		cout<<1<<" "<<w;
//		cout<<"a";
		return 0;
	}
	else if((w/n)%2==0){
		if(w%n==0){
		cout<<w/n<<" "<<1;
//		cout<<"b";	
		}
		else{
			cout<<w/n+1<<" "<<w%n;
//			cout<<"c";
		}
		return 0;
	}
	else{
		if(w%n==0) cout<<w/n<<" "<<n;
		else cout<<w/n+1<<" "<<n-(w%n)+1;
	}
	return 0;
}