#include<bits/stdc++.h>
using namespace std;

bool cmp(string a,string b)
{
    return a > b;
}

char s[1000001];
string a[1000001],n = "0123456789";
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int len_1 = strlen(s),t = 0;
    for(int i = 0;i < len_1;i++)
    {
        for(int p = 0;p <= 9;p++)
        {
            if(s[i] == n[p])
            {
                a[t] = s[i];
                t++;
            }
        }
    }
    sort(a,a+t,cmp);
    for(int j = 0;j < t;j++)
        cout << a[j];
    return 0;
}
