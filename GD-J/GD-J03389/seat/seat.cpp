#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int a[105],n,m,b[105],c;
    cin>>n>>m; 
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<n*m;i++){
		for(int j=1;j<=i;j++){
			if(b[i]>b[i-1])swap(b[i],b[i-1]);
		}
	}
	for(int i=0;i<n*m;i++){
		if(b[i]==a[0]){
			if(i/n%2==0)cout<<(i/n)+1<<" "<<(i%n)+1;
			else cout<<(i/n)+1<<" "<<n-(i%n);
			break;
		}
	}
	return 0;
}
