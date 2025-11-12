#include <bits/stdc++.h>
using namespace std;
int k[1000005],xb=0;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin >> a;
    for(int i=0;i<a.size();i++)
        if('0'<=a[i] && a[i]<='9')
            k[++xb]=a[i]-'0';
    sort(k+1,k+xb+1,cmp);
    for(int i=1;i<=xb;i++)
        cout << k[i];
    return 0;
}
