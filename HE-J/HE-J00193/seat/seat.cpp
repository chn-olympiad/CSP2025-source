#include<iostream>
#include<algorithem>
using namespace std;

int main(){
	int m,n,x;
	int a[1000010];
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a[1],a[m*n]);
	
	
	return 0;
}
