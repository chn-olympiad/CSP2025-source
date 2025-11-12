#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
string s;
long long a[20],ans[1000010],k = 1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(long long i = 0;i < s.size();i++)
    {
        if('0' <= s[i] && s[i] <= '9')
        {
            long long b = s[i] - '0';
            a[b]++;
        }

    }
    for(long long i = 9;i >= 0;i--)
    {
        if(a[i])
        {
            for(long long j = 1;j <= a[i];j++)
            {
                ans[k] = i;
                k++;
            }

        }
    }
    for(long long i = 1;i < k;i++)
        cout << ans[i];
    return 0;
}
