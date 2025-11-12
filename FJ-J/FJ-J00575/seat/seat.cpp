#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[110],s;
void solve(int x){
	int y,z;
	if(x%n==0){
		if((x/n)%2==1){
			y=x/n,z=n;
		}else{
			y=x/n,z=1;
		}
	}
	else if(((x/n)+1)%2==1){
		y=(x/n)+1,z=x%n;
	}
	else if(((x/n)+1)%2==0){
		y=(x/n)+1,z=n-(x%n)+1;
	}
	cout<<y<<" "<<z;
	return ; 
}
signed main(){
	freopen("seat.out","w",stdout);
	freopen("seat.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==s){
			solve(n*m-i+1);
		}
	}
	return 0; 
}
