#include<bits/stdc++.h>
using namespace std;
int s[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0); 
	int n,m,rs,rk;
	cin>>n>>m;
	cin>>s[1];
	rs=s[1];
	rk=1;
	for(int i=2;i<=n*m;i++){
		cin>>s[i];
		if(s[i]>rs){
			rk++;
		}
	}
	int c=rk/n+1,r;
	if(rk%n==0){
		c--;
	}
	if(c%2==0){
		r=n-(rk%n);
		if(r==0){
			r=1;
		}
	}else{
		r=rk%n;
		if(r==0){
			r=n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
