#include <bits/stdc++.h>
using namespace std;
int n,m,a[110];
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			if(i<=n){
				cout<<"1"<<" "<<i;
			}
			else{
				int j=i/n;
				if((j+1)%2==1){
					cout<<j+1<<" "<<i%n;
				}
				else{
					cout<<j+1<<" "<<n-i%n+1;
				}
			}
		}
	}
	return 0;
} 