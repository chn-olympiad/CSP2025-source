#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin >> a;
    int cnt = 0;
    for(int i = 0; i < a.size();i++)
    {
        if(a[i] >= '0'&& a[i] <= '9')
        {
            cnt++;
        }
    }
    int b[cnt] = {0};
    int t=0;
    for(int i = 0; i < a.size();i++)
    {
        if(a[i] >= '0'&& a[i] <= '9')
        {
            b[t] = a[i] - 48;
            t++;
        }
    }
    for(int i = 0; i < cnt;i++)
    {
        for(int p = 0; p < cnt;p++)
        {
            if(b[i] > b[p])
            {
                swap(b[i],b[p]);
            }
        }

    }
    for(int i = 0; i < cnt;i++)
    {
        cout<< b[i];
    }



    return 0;
}

