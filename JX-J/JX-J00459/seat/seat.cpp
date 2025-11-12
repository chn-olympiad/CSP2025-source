#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],s,w,asd,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	w=a[1];
	sort(a+1,a+s+1);
	for(int i=1;i<=s;i++){
		if(a[i]==w){
			asd=s-i+1;
			break;
		}
	}
	c=asd/n;
	if(asd%n==0)r=m;
	else {
		if(c%2==1)r=m-asd%n+1;
		else r=asd%n;
		c++;
	}
	cout<<c<<" "<<r;
	return 0;
}
