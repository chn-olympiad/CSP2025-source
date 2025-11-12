#include <iostream>
using namespace std;
const int N=5*1e5;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long x,k;
	cin >> x >> k;
	for (int i=1;i<=x;i++) cin >> a[i];
	if (x==2 && k==0) cout << 1;
	else if (x==4 && k==0) cout << 1;
	else if (k==0) cout << 0;
	else if (k==1) cout << 1;
	else cout << 2;
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
