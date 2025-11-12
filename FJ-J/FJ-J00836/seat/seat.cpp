#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m,a[105],s,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			s=i;
			break;
		}
	}
	if(s%n==0){
		c=s/n;
		if(c%2==0){
			r=n;
		}
		else r=1;
	}
	else{
		c=s/n+1;
		if(c%2==0){
			r=n-(s%n)+1;
		}
		else r=s%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
