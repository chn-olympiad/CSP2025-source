#include<bits/stdc++.h>
using namespace std;
int n,m,l,a[105],s,t,c,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++)cin>>a[i];
	s=a[1];
	sort(a+1,a+1+l,cmp);
	while(a[t]!=s){
		t++;
	}
	//t--;
	//cout<<t<<endl;
	c=t%n;
	r=t/n+1;
	//cout<<c<<endl<<r<<endl;
	if(c==0){
		r--;
		c=n;
	}
	if(r%2==0)c=n-c+1;
	cout<<r<<' '<<c;
	return 0;
}
