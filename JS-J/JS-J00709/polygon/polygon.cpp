#include <bits/stdc++.h>
using namespace std;
int n;
long long ans=0,m=-1,s=0;
vector <int> a(n);
void d(int i)
{
    if(s>= 2*m)
    {
        ans++;
        return;
    }
    for(int x = 0;x < n;x++)
    {
        if(a[x] > m)
        {
            m = a[x];
        }
    }
    s+=a[i];
    d(i+1);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    for(int i = 3;i < n;i++)
    {
        d(i);
    }
    long long as = ans%998;
    cout << as;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
