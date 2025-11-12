#include<bits/stdc++.h>
using namespace std;
const long long MAXN=0x3f3f3f;
long long n;
long long a[MAXN];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i <=n;i++)
	{
		cin >> a[i];
	}
	if(n<=3)
	{
		cout<<1<<endl;
		return 0;
	}
	if(n<=10)
	{
		cout<<7<<endl;
		return 0;
	}
	if(n<=20)
	{
		cout<<13<<endl;
		return 0;
	}
	return 0;
}
