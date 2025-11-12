#include <bits/stdc++.h>
using namespace std;
int x1,x2,x3,x4,x5,x6,x7,x8,x9,x0;
char s[1000005];
string a;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    a+=' ';
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '0')
            x0++;
        if (s[i] == '1')
            x1++;
        if (s[i] == '2')
            x2++;
        if (s[i] == '3')
            x3++;
        if (s[i] == '4')
            x4++;
        if (s[i] == '5')
            x5++;
        if (s[i] == '6')
            x6++;
        if (s[i] == '7')
            x7++;
        if (s[i] == '8')
            x8++;
        if (s[i] == '9')
            x9++;
    }
    a+='9'*x9+'8'*x8+'7'*x7+'6'*x6+'5'*x5+'4'*x4+'3'*x3+'2'*x2+'1'*x1+'0'*x0;
    cout << a;
    return 0;
}
