#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m,a[1005]={},c=0,r=0,x=1,num=0;
	cin>>n>>m;
	cin>>a[0];
	num=a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>num) x++;
	}
	c=x/n+x%2;
	if(c%2==1){
		r=x%n;
		if(r==0) r=n;
	}else if(c%2==0){
		r=n-(x-n*c+n)+1;
	}
	cout<<c<<" "<<r;
	return 0;
}