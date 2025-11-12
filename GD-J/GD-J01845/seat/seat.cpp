#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200;
int n,m;
int a[N];
int k;
int id=1;//µÚ¼¸Ãû 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			id++;
		}
	}
	k=id/n;
	if(id%n!=0){
		k++;
		if(k%2==1){
			cout<<k<<" "<<id-(n*(k-1)+1)+1;
		}
		else{
			cout<<k<<" "<<(n*k)-id+1;
		}
	}
	else{
		if(k%2==1){
			cout<<k<<" "<<n;
		}
		else{
			cout<<k<<" "<<1;
		}
	}
	return 0;
}
