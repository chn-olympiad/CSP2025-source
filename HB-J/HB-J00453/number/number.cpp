#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    string a;
    cin >> a;
    int len = a.size();
    int ans[1000005];
    int len2 = 0;
    for(int i = 0; i < len; i++)
    {
        if(a[i] >= '0' && a[i] <='9')
        {
            ans[len2] = a[i] - '0';
            len2++;
        }
    }
    sort(ans , ans+len2);
    for(int i = len2-1; i >= 0 ; i--)
    {
        cout << ans[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
