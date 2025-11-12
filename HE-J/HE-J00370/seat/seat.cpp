#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r","stdin")
	//freopen("number.out","w","stdout")
	int n,m,i,t;
	cin>>n>>m;
	int a[n*m];
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	for(i=1;i<=n*m;i++){
		if(a[i+1]>a[i]){
			a[i]=a[i+1];
		}
	}
	for(i=1;i<=n*m;i++){
		if(a[i]==t){
			a[i]=a[i+1];
			cout<<n<<" "<<m;
		}
	}
	return 0;
}
