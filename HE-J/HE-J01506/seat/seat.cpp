#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m=0,n=0;
	int c=1,r=0;
	int a1=0;
    cin>>m>>n;
	int b=m*n;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+b)
	for(int i=1;i<=b;i++){
		if(a[i]=a1) {
		a1=i;
		break;
	}
		else continue;
	}
	while(a1<n){
		a1=a1-n;
		c=c+1;
	}
	if(c%2==0) r=n-a1+1;
	else r=a1;
	cout<<c<<" "<<r;
	return 0;
}
