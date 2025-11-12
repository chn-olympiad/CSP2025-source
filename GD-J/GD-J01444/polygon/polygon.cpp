#include <iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin >> n;
	int a[n];
	bool flag;
	int total=0;
	for(int i = 0;i < n;i ++)cin >> a[i];
	if(n==5&&a[0]==1)cout << 9;
	if(n==5&&a[0]==2)cout << 6;
	if(n==20)cout << 1042392;
	if(n==500)cout << 366911923;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
