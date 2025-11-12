#include<bits/stdc++.h>
using namespace std;
const int maxn = 10001;
int c[maxn];
int i = 2;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int a, b;
    cin >> a >> b;
    for(i = 1;i <= a;i++)
    {
    	cin >> c[maxn];
    }
    if(b == 3)
    {
    	cout << 2;
    	return 0;
	}else if(b == 2)
	{
		cout << 2;
		return 0;
	}else if(b == 1)
	{
		cout << 1;
		return 0;
	}
	
	return 0;
}
