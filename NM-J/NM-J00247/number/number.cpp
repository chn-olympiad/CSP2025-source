#include <bits/stdc++.h>
#include <bits/c++config.h>
#include <bits/memoryfwd.h>
using namespace std;
int a[1000002],n=0;
bool c(int x,int y)
{
    return x>y;
}
int main()
{
    freopen ("number.in"," r",stdin);
    freopen ("number.out"," w",stdout);
    string s;
    std::cin>>s;
    for(int i=0;i<=s.length();i++)
    {
        if('0'>=s[i]>='9')
        {
            a[i]=s[i]-'0';
            n++;
        }
    }
    sort(a,a+n,c);
    for(int i=0;i<=n;i--)
    {
        std::cout<<a[i];
    }
    return 0;
}
