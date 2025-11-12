#include<bits/stdc++.h>
using namespace std;
const int M= 998244353;
long long s=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	for(int i=1;i<=114514;i++)
	{
		s = s * i % M;//RP++;
	}
	cout<<s;
	return 0;
}//goodbye-oi
