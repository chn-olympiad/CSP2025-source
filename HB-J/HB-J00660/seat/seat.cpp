#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,a[2000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt=1; 
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1])cnt++;
	}
	if(((cnt+n-1)/n)%2==0){
		if(cnt%n==0)cout<<(cnt+n-1)/n<<" "<<1;
		else cout<<(cnt+n-1)/n<<" "<<n-cnt%n+1;
	}
	else {
		if(cnt%n==0)cout<<(cnt+n-1)/n<<" "<<n;
		else cout<<(cnt+n-1)/n<<" "<<cnt%n;
	}

	return 0;
}
