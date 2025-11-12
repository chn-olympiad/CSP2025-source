#include <iostream>
using namespace std;
const int M = 101;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	int c,r,a[M],s = 1;
	cin>>n>>m;
	for(int i = 0;i < M;i++) a[i] = -1;
	cin>>a[1];
	int num = a[1];
	for(int i = 2;i <= n*m;i++){
		cin>>a[i];
		if(a[1] < a[i]) s++;
	}
	if(s%n == 0) c = s/n;
	else if(s%n != 0) c = s/n+1;
	if(c%2 == 0){
		if(s%n==0) r = 1;
		else if(s%n != 0) r = n+1-s%n;
	}
	else if(c%2 != 0){
		if(s%n==0) r = n;
		else if(s%n != 0) r = s%n;
	} 
	cout<<c<<' '<<r;

	return 0;
} 