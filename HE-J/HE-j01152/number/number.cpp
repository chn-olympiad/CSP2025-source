#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N];
int c;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w".stdout);
	string s;
	cin >> s;
	for(int i = 1;i <= s;i++)
    {
         a[i] % 10 / 10;
         if(a[i] != a[i - 1])
         {
             c = sort(a[i],a[i] + 1);
             if(c > a[i])
             {
                c++;

             }
             if(max(c) > a[i])
             {
                 c / 2;
             }
         }
         break;
    }
    cout << c;
	return 0;
}
