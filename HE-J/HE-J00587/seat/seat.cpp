#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
} 
int a[110],n,m,num,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			num=i;
			break;
		}
	}
	if(num%n!=0){
		c=num/n+1;
		if(c%2==0){
			r=n-num%n+1;
		}
		else{
			r=num%n;
		}
	}
	else{
		c=num/n;
		if(c%2==0){
			r=1;
		}
		else{
			r=n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
} 
