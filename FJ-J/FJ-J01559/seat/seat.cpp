#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int n,m,a,r[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>r[i];
		if(i==1){
			a=r[i];
		}
	} 
	sort(r+1,r+1+n*m);
	int k;
	for(int i=1;i<=n*m;i++){
		if(r[i]==a){
			k=i;
			break;
		}
	}
	k=n*m-k+1;
	int z;
	if(k%n==0){
		cout<<k/n;
		z=k/n;
	}else{
		cout<<k/n+1;
		z=k/n+1;
	}
	cout<<" ";
	if(z%2==0){
		if(k%n==0){
			cout<<1;
		}else{
			cout<<n-k%n+1;
		}
	}else{
		if(k%n==0){
			cout<<n;
		}else{
			cout<<k%n;
		}
	}
	return 0;
} 
