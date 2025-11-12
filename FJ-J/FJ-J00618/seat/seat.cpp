#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,x,c,r;
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+s+1);
	for(int i=1;i<=s;i++){
		if(R==a[i])
			x=i;
	}
	r=s-x+1;
	if(r%n==0){
		c=r/n;
		r=n;
	}
	else{
		c=r/n+1;
		r=r%n;
	}	
	if(c%2==0){
		cout<<c<<" "<<n-r+1;
	}else{
		cout<<c<<" "<<r;
	}
	return 0;
}