#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in ","r",stdin);
	freopen("seat.out ","w",stdout);
	long a[114],n,m,b[114][514],o=1,x,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(a[1]<a[i]){
			o++;
		}
	}
	if(n>=o){
		cout<<"1 "<<o;
	}
	else if(o>n&&o%n!=0){
		x=o/n+1;
		y=o%n;
		if(x%2==1)
		cout<<x<<" "<<y;
		else if(x%2==0){
			cout<<x<<" "<<n-y+1;
		}
	}
	else if(o%n==0){
		x=o/n;
		
		if(x%2==1)
		cout<<x<<" "<<n;
		else if(x%2==0){
			cout<<x<<" "<<1;
		}
	}
	return 0;
}  