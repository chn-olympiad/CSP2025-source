#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,h;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	h=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i;j<=n*m;j++){
		    if(a[i]<a[j]){
		    	swap(a[i],a[j]);
			}
	    }
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==h){
			if(i%n==0){
				if((i/n)%2==0){
					cout<<i/n<<" "<<1;
					return 0;
				}
				else{
					cout<<i/n<<" "<<n;
					return 0;
				}
			}
			else if((i/n+1)%2==0){
				cout<<i/n+1<<" "<<n-(i%n)+1;
				return 0;
			}
			else{
				cout<<i/n+1<<" "<<i%n;
				return 0;
			}
		}
	}
	return 0;
}
