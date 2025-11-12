#include<bits/stdc++.h>
using namespace std;
const int MAXN=0x3f3f3f;
long long maxx=-1;
long long n,k,num;
long long a[MAXN];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n >>k;
	for(int i=1;i <= n;i++){
		cin >> a[i];
		if(a[i]^k>maxx)
		{
			maxx=a[i]^k;
			num=i;
		}
	}
	cout<<a[num]-1;
	return 0;
}
