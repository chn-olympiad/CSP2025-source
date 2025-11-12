#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
int n,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	while(cin>>n)if(n==0)ans++;
	cout<<ans;
	return 0;
}
