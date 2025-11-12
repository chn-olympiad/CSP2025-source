#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],c,r,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])
		cnt++;
	}
	if(cnt%n==0){
		c=cnt/n;
	}
	else{
		c=cnt/n+1;
	}
	if(c%2==0){
		if(cnt%n==0)
		r=1;
		else
		r=(n-cnt%n+1);
	}
	else{
		if(cnt%n==0)
		r=n;
		else
		r=cnt%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
