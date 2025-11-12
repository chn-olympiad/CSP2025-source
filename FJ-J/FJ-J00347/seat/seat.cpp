#include<bits/stdc++.h>
using namespace std;
int a[105],sum=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])sum++;
	}
	if(sum%n==0){
		x=sum/n;
		if(x%2==0)y=1;
		else y=n;
	}
	else {
		x=sum/n+1;
		if(x%2==0)y=n+1-(sum%n);
		else y=sum%n;
	}
	cout<<x<<" "<<y;
} 
