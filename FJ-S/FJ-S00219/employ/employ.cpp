#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll read()
{
	ll a=0,j=1;char b=getchar();
	for(;b>'9'||b<'0';b=getchar())if(b=='-') j=-1;
	for(;b>='0'&&b<='9';a=a*10+b-48,b=getchar());
	return a*j;
}
int main()
{
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	
	return 0;
}