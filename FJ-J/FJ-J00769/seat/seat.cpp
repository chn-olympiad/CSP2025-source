#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[1005],sum,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>x) sum++;
	}
	c=sum/n+1;
	if(c%2==1){
		r=sum%n+1;
	}else{
		r=n-sum%n;
	}
	cout<<c<<" "<<r;
	return 0;
}


