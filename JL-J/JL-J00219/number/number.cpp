#include<bits/stdc++.h>
using namespace std;
long long a[1001000];
bool cmp(int n,int m)
{
    return n > m;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int num = 0;
    for(int i = 0;i < s.size();i ++)
    {

        if(s[i] <= '9' && s[i] >= '0')
        {
            a[num] = s[i] - '0';
            num ++;
        }
    }
    sort(a,a+num,cmp);
    for(int i = 0;i < num;i ++)
    {
        cout << a[i];
    }
    return 0;
}
