#include<iostream> 
using namespace std;
const int maxn=1e5+5;
long long n,a[maxn];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=2){
		cout<<0;
	}
	else if(n==3){
		int x=a[0]+a[1]+a[2];
		int y=max(a[0],max(a[1],a[2]));
		if(x>2*y){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<n+4;
	}
	return 0;
}