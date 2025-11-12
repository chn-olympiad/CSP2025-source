#include <bits/stdc++.h>

using namespace std;

int a[1000000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin >> s;

    int j = 0;
    int cnt = 0;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(isdigit(s[i]) != 0)
        {
            a[j] = s[i] - '0';
            j++;
            if(a[j] == 0)
                cnt++;
        }
    }
    sort(a , a + j);

    for(int i = j - 1 ; i >= 0 ; i--)
    {
        if(a[i] == 0)
            cnt--;
        if(cnt > 0)
            cout << a[i];
        else
            break;
    }

    return 0;
}
