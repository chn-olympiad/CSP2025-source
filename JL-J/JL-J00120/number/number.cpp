#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long s;
    scanf("%lld",&s);
    int h=1;
    int w=s;
    for(int i=1;i<=s;i++)
    {
        if(w/10>0)
        {
            h++;
            w/=10;
        }
        else
        {
            break;
        }
    }
    for(int i=1;i<=h;i++)
    {
        a[i]=s%10;
        s=s/10;
    }
    sort(a+1,a+1+h);
    for(int i=h;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
