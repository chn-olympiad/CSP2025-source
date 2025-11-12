#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
string s;
long long a[15];
int main(){
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	for (long long i=0;i<len;++i){
		long long x=s[i]-'0';
		if (x>=0&&x<=9)
			a[x]++;
	}
	for (long long i=9;i>=0;--i)
		for (int j=a[i];j>0;--j)
			printf ("%lld",i);
	return 0;
}
