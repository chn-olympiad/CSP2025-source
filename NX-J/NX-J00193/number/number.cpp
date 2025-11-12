#include<bits/stdc++.h>
using namespace std;

int a[1000001];

bool sort_state(int i1, int i2)
{
    return i1>i2;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long n=0;
    string s;
    cin >>s;
    for(long long i=0; i<s.size(); i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            a[n] = s[i]-'0';
            n++;
        }
    }
    sort(a, a+n, sort_state);

    for(long long i=0; i<n; i++)
    {
        cout <<a[i];
    }
    return 0;
}
