#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,a[101],o,x,y;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
		cin>>a[i];
	o=a[1];
	sort(a+1,a+n*m+1);
	for(i=1;i<=n*m;i++){
		if(a[i]==o){
			o=m*n-i+1;
			break;
		}
	}
	if(o%n!=0){
		x=o/n+1;
		if(o/n==1||o/n==3||o/n==5||o/n==7||o/n==9)
			y=n-o%n+1;
		if(o/n==0||o/n==2||o/n==4||o/n==6||o/n==8)
			y=o%n;
		cout<<x<<" "<<y;
	}
	else{
		x=o/n;
		if(o/n==1||o/n==3||o/n==5||o/n==7||o/n==9)
			y=n;
		else
			y=1;
		cout<<x<<" "<<y;
	}
	return 0;
}
