#include<iostream>
using namespace std;
int n,k,a[1001];
void bubble(){
	for(int i=n; i>1; i--){
		for(int j=1; j<i; j++){
			if(a[j]<a[j+1]) swap(a[j],a[j+1]);
		}
	}
}
int main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	bubble();
	if(a[1]%2==0) cout<<a[1]+1;
	else cout<<a[1]-1;
	return 0;
}
