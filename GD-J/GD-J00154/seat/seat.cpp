#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],paiming=0;
long long c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int aa=a[1];
	sort(a+1,a+m*n+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==aa){
			paiming=n*m+1-i;
			break;
		}
	}
	if(paiming%n==0){
		c=paiming/n;
	}
	else{
		c=paiming/n+1;
	}
	if(c%2!=0){
		r=paiming%n;
		if(r==0) r=n;
	}
	else{
		r=n+1-paiming%n;
		if(r==0) r=1;
	}
	cout<<c<<" "<<r;
	return 0;
}
