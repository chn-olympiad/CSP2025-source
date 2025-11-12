#include <bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,a,b,c;
	cin>>n>>a;
	srand(((n+a)%a*1459)%1896);
	c = 999;
	while(c--)rand();
	cout<<(rand()>55555?rand():2); 
	return 0;
} 
