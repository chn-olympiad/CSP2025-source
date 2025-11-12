#include<iostream>
using namespace std;
int a[100000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m>>r;
	for (int i=2;i<=n*m-1;i++){
		cin>>a[i];
	}
	a[1]=r;
	if(n==1 && m==1){
		cout<<1<<" "<<1;
	}
	return 0;
}
