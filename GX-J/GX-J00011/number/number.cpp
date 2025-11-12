#include <bits/stdc++.h>
using namespace std;
string s;
char num[1000005];
long long a=1;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n;i++)
    {
        if((s[i]) >= '0' && (s[i] <= '9')) num[a++] = s[i];
    }
    sort(num+1,num+a,greater<char>());
    for(int i = 1; i < a;i++)
    {
        cout << num[i];
    }
    cout << endl;
    return 0;
}
