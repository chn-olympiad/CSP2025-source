#include<iostream>
#include<cmath>
#include<algorithm>
int a[15];
char n;
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>n) if('0'<=n&&'9'>=n) a[n-'0']++;
	for(int i=9;i>=0;i--) while(a[i]--) cout<<i;
	return 0;
}