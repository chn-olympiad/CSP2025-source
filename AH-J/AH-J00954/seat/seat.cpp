#include<bits/stdc++.h>
using namespace std;
long long a[100005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	long long n,m,t=1;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
		if(i>=2&&a[i]>a[1])
			t++;
	}
	cout<<(t+n-1)/n<<" ";
	if(((t+n-1)/n)%2==1){
		long long u=t%n;
		if(u==0) u=n;
		cout<<u;
	}
	else{
		long long u=t%n;
		if(u==0) u=n;
		cout<<n-u+1;
	}
	return 0;
}
