#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
bool px(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i]; 
	}
	int b=a[1],c,x,y;
	sort(a+1,a+n*m+1,px);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			c=i;
			break;
		}
	}
		if(c%n==0){
			x=c/n;
		}else{
			x=c/n+1;
		}
	
	if(x%2==0){
		y=m-c%n;
	}else{
		if(c%n==0){
			y=m;
		}else{
			y=c%n;
		}
	}
	cout<<x<<" "<<y;
	return 0;
	}
	
