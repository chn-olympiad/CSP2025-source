#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string str;
int a[N];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin >> str;
    int k = 0;
    for(int i = 0;i < str.length(); ++ i)
    {
    	if(str[i] >= '0' && str[i] <= '9')
    	{
    		a[k++] = str[i] - '0';
		}
	}
	sort(a,a + k);
	for(int i = k - 1;i >= 0; -- i)
	 cout << a[i];
	return 0;
}
