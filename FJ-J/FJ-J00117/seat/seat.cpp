#include<bits/stdc++.h>
using namespace std;
long long arr[10001],a,b,n,c,d,x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	n=a*b;
	for(int i=1;i<=n;i++){
			cin>>arr[i];
	}
	c=arr[1];
	sort(arr+1,arr+n+1);
	for(int i=n;i>=1;i--){
		if(arr[i]==c){
			d=n-i+1;
		}
	}
	while(1){
		if(d>a){
			d-=a;
			x++;
		}else{
			y=d;
			break;
		}
	}
	if(x%2==0){
		y=b-y+1;
	}
	cout<<x<<" "<<y;
	return 0;
}

