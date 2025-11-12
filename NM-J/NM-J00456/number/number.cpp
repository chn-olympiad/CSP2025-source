#include<bits/stdc++.h>
using namespace std;
int main()
{
 	freopen("number.in","r",stdin);
   	freopen("number.out","w",stdout);
    string s;
    cin >> s;
    char d;
    for(char c:s)
	{
        if (isdigit(c)) {
            d.p(c);
        }
    }
    sort(d.begin(), digits.end(), g<char>());
    string r(d.begin(), d.end());
    cout << r<< endl;
    return 0;
}
