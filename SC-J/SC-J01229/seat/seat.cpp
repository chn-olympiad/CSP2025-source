#include<bits/stdc++.h>
using namespace std;
long long n,m,s,x,y,c,r,a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	s=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			x=i;
			break;
		}
	}
	c=ceil(x*1.0/n);
	y=(x%n==0?n:x%n);
	r=(c%2==0?n-y+1:y);
	cout<<c<<" "<<r;
	return 0;
}