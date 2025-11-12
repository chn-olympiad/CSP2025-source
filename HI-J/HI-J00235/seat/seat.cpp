#include<bits/stdc++.h>
using namespace std;
int n,m;
int r,c;
int a[120];
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l=n*m;
	for(int i=0;i<l;i++){
		cin>>a[i];
	}
	int x=a[0];
	sort(a,a+l,cmp);
	for(int i=0;i<l;i++){
		if(x==a[i]){
			x=i;
			break;
		}
	}
	if((x+1)%n==0){
		c=(x+1)/n;
		if(c%2==0){
			r=1;
		}
		else{
			r=n;
		}
	}
	else{
		c=(x+1)/n+1;
		if(c%2==0){
			r=n-(x+1)%n+1;
		}
		else{
			r=(x+1)%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
