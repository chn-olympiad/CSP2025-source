#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y,b=0,c;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		b++;
		if(a[i]==c){
			break;
		}
	}
	y=b/n;
	if(y*n!=b){
		y+=1;
		if(y%2==1){
			x=b%n;	
		}else{
			x=n+1-(b%n);
		}
	}else{
		if(y%2==1){
			x=n;	
		}else{
			x=1;
		}
	}
	cout<<y<<' '<<x;
	return 0;
}