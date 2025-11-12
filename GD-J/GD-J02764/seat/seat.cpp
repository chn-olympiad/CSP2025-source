#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	b=a[1];
	sort(a+1,a+n*m+1);
	int c=upper_bound(a+1,a+m*n,b)-a-1;
	c=n*m-c+1;
	double d=c;
	cout<<ceil(d/n)<<" ";
	if(int(ceil(d/n))%2==0){
		if(c%n!=0) cout<<n-(c%n)+1;
		else cout<<"1";
	}
	else{
		if(c%n!=0) cout<<c%n;
		else cout<<n;
	}
	return 0;
} 
