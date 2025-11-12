#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005],n;
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i <= 100005;i++)
    {
        if(s[i] == '9'||s[i] == '8'||s[i] == '7'||s[i] == '6'||s[i] == '5'||s[i] == '4'||s[i] == '3'||s[i] == '2'||s[i] == '1'||s[i] == '0')
        {
             a[n] = s[i]-48;
             n++;
        }
    }
    sort(a,a+n+1,cmp);
    for(int i = 0;i <= n-1;i++)
    {
          cout << a[i];
    }
    return 0;
}
