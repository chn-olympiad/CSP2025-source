#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int n = s.size();
    int a[100000];
    int len = 0;
    for(int i = 0;i<n;i++)
    {
        if(s[i] >='0' && s[i] <= '9')
        {
            int num = s[i] -'0';
            a[i] = num;
            len ++;
        }
    }
    sort(a,a+n,[=](int a,int b)
         {
             return a > b;
         });
    for(int i = 0;i<len;i++)
    {
        if(a[i] == -1)
        {
            break;
        }
        cout << a[i];
    }
}
