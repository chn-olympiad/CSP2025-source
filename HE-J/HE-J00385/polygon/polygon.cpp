#include<bits/stdc++.h>
using namespace std;
int n,m,k=1;
int a[120];
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]){
			k++;
		}
	}
	int l=(k-1)/n+1;
	cout<<l<<' ';
	if(l%2==0){
	if(k%n==0){
			cout<<1<<endl;
		}else{
			cout<<n-(k%n)+1<<endl;
		}
	}else{
		if(k%n==0){
			cout<<n<<endl;
		}else{
			cout<<k%n<<endl;
		}
	}
	return 0;
}
