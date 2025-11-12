#include<bits/stdc++.h>
using namespace std;

int a[1005];
bool c(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){	
		cin>>a[i];	
	}
	int t=a[1],x=1,y=1;
	sort(a+1,a+n*m+1,c);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			
			cout<<y<<" "<<x;
		}
		if(y%2!=0){
			
			x++;
			if(x>n){
				x=n;
				y++;
			}
		}
		else{
			x--;
			if(x<=0){
				x=1;
				y++;
			}
		}
	}
	return 0;
} 
