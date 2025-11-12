#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000],h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			h++;
		}
	}
	int x=h/n+1,y=(h+1)%n;
	if(y==0){
		y=n;
	}
	if(x%2==1){
		cout<<x<<" "<<y;
	}else{
		cout<<x<<" "<<n-y+1;
	}
	return 0;
} 
