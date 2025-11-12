#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5];
int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n<3){
		cout<<0;
	}else{
		if(a[0]+a[1]+a[2]>a[2]*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
} 
