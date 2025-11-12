#include<bits/stdc++.h>
using namespace std;
int b[10000],j,t;
bool cmp(int x1,int x2){
	return x1>x2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,h,x,y;
	cin>>n>>m;
	h=n*m;
	for(int i=1;i<=h;i++){
		int p;
		cin>>p;
		if(i==1) t=p;
		b[i]=p;
	}
	sort(b+1,b+h+1,cmp);
	for(int i=1;i<=h;i++){
		if(b[i]==t) j=i;
	}
	if(j%n==0) x=j/n;
	else x=j/n+1;
	if(x%2==0&&j%n==0) y=1;
	else if(j%n==0) y=n;
	else if(x%2==0) y=n-j%n+1;
	else y=j%n;
	cout<<x<<" "<<y;
	return 0;
}
