#include <bits/stdc++.h>
using namespace std;
int a[500005],n,cnt=0,q=1;
int main()
{
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    cout << 1;
    cin >> n;
    for(int i = 1;i <= n-1;i++)
    {
        cout << 1;
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cout << 1;
        cout <<  a[i];
    }
    cout << 1;
    int c = 1;
    for(int i = 1;i <= n;i++)
    {
        q *= 2;
    }
    while(c <q)
    {
        int sum=0,all=0,maxn=0,pos=0,x=c;
        while(x)
        {
            if(x%2==1)
            {
                sum++;
                all+=a[pos];
                maxn=max(maxn,a[pos]);
            }
            pos++;
        }
        if(sum >= 3 && all >maxn*2)
        {
            cnt++;
        }
        c++;
    }
    cout << cnt;
}
