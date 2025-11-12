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
string s;
long long a[1000010],k=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	for(long long i=0;i<len;i++)
		if(s[i]>='0' && s[i]<='9')
			{a[k]=s[i]-48;k++;}
	sort(a+1,a+k+1,cmp);
	for(long long i=1;i<k;i++)
		cout<<a[i];
	return 0;
}
