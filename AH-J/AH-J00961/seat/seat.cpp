#include <bits/stdc++.h>
using namespace std;
int n,m,arr[110],t,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
	}
	t=arr[0];
	sort(arr,arr+n*m);
	while(arr[k]!=t){
		k++;
	}
	k=n*m-k-1;
	cout<<int(k/n)+1<<" "<<(!(int(k/n)%2))*((k%n)+1)+(int(k/n)%2)*(n-k%n);
	return 0;
}

