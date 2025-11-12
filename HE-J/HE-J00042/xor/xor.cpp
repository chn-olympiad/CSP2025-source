#include <iostream>
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	int a[m];
	for(int i=0;i<m;i++)cin>>a[i];
	cout<<m*(m-1)/2;
	return 0;
}
