#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[j]>a[i]){
				swap(a[i],a[j]);
			}
		} 
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			y=i;
			break;
		}
	}
	if(y<=n){
		cout<<1<<' '<<n;
	}else{
		if(y%n==0){
			if((y/n)%2==0){
				cout<<y/n<<' '<<1;
			}else{
				cout<<y/n<<' '<<n;
			}
		}else{
			if((y/n+1)%2==0){
				cout<<y/n+1<<' '<<n-y%n+1;
			}else{
				cout<<y/n+1<<' '<<y%n;
			}
		}
	}
	return 0;
}