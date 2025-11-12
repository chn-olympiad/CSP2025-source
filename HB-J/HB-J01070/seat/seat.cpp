#include<bits/stdc++.h>
using namespace std;
int n,m,a,b=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int t;
		cin>>t;
		if(i==1)a=t;
		else{
			if(t>a)b++;
		}
	}
	if(b%n>=1){
		c=b/n+1;
		if(c%2==1)r=b%n;
		else r=n+1-(b%n);
	}
	else if(b%n==0){
		c=b/n;
		if(c%2==1)r=n;
		else r=1;
	}
	cout<<c<<' '<<r;
	return 0;
}
