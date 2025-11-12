#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a;
	cin>>a;
	int x=1;
	for(int i=2;i<=n*m;i++){
		int b;cin>>b;
		if(b>a)x++;
	}
	if(x%n==0&&(x/n)%2==0) cout<<(x/n)<<" "<<1;
	else if(x%n==0&&(x/n)%2!=0) cout<<(x/n)<<" "<<n;
	else if(x%n>0&&(x/n)%2==0) cout<<(x/n+1)<<" "<<x%n;
	else if(x%n>0&&(x/n)%2!=0) cout<<(x/n+1)<<" "<<n-x%n+1;
	return 0;
}
