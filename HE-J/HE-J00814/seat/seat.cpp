#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,c,r,chengji=0,biao=0;
	cin>>n>>m;
	long long a[n*m+1];
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
		chengji=a[1];
	}
	sort(a+1,a+1+n*m);
	for(long long i=1;i<=n*m;i++){
		if(a[i]==chengji)
			biao=i;
	}
	biao=n*m-biao+1;
	if(biao==n+1){
		c=2;
		r=2;
		cout<<c<<" "<<r;
		return 0;
	}
	else if(biao==n){
		c=1;
		r=m;
		cout<<c<<" "<<r;
		return 0;
	}
	else {
		c=biao/2;
		r=biao%2;
		cout<<c<<" "<<r;
		return 0;
	}
	return 0;
}
