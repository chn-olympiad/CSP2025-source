#include<iostream>
using namespace std;
int a[6001];
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	int num=0;
	for (int i=3;i<=n;i++){
		int x=1;
		for (int j=1;j<=i;j++){
			x*=j;
		}
		int y=1;
		for (int j=n;j>n-i;j--)y*=j;
		num+=y/x;
	}
	cout<<num;
	return 0; 
}
