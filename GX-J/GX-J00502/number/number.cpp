#include <bits/stdc++.h>
using namespace std;
string s;
long long sum,a[1000005];
bool cmp(int x,int y)
{
    return x >= y;
}
int main()
{
    freopen ("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            sum++;
            a[sum] = s[i] - '0';
        }
    }
    sort (a+1,a+sum+1,cmp);
    int ans = a[1];
    for(int i =2;i <= sum; i++)
    {
        ans *= 10;
        ans+=a[i];
    }
    cout<< ans;
    return 0;
}
