#include <bits/stdc++.h>
using namespace std;

const int mod=998244353;


int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	mt19937 mt;
	mt.seed(chrono::system_clock::now().time_since_epoch().count());
	cout<<(uniform_int_distribution<unsigned int>(0,INT_MAX)(mt)%mod);
	return 0;
}
