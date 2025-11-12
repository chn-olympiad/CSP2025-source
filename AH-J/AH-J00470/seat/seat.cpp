#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105];
	int n,m;
	cin>>n>>m;
	int x,y;
	int c;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		c=a[1];
	}
	for(int i=1;i<=n*m;i++){
		int temp;
		if(a[i]<a[i+1]){
			temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
		}
		
	}
	
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
			if(i<=n){
				x=1;
				y=i;
			}
			else if(i%n!=0 && (i/n+1)%2==0){
				x=(i/n+1);
				y=n-(i%n-1);
			}	
			else if(i%n==0){
				if(i/n%2==0){
					x=i/n;
					y=1;
				}
				else{
					x=i/n;
					y=n;
				}
			}
			else if(i%n!=0 && (i/n+1)%2!=0){
				x=(i/n+1);
				y=i%n;
			}
			cout<<x<<" "<<y;
		}
	}

	return 0;
}
