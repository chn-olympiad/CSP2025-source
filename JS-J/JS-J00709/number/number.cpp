#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    long long n = 0,pos,x=0;
    long long l = s.length();
    int a[999999];
    vector <bool> f(l,true);
    for(int i = 0;i < l;i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            continue;
        }
        else
        {
            a[x] = s[i]-48;
            x++;
        }
    }
    for(int i = 0;i < x+1;i++)
    {
        int m = -1;
        for(int j = 0;j < x+1;j++)
        {
            if(f[j] == true)
            {
                if(a[j] > m)
                {
                    m = a[j];
                    pos = j;
                }
            }
        }
        f[pos] = false;
        if(a[-2]!=m)
        {
            n = m+n*10;
        }
        else{
            n += m;
        }
    }
    cout << n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
