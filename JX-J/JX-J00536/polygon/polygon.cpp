#include<bits/stdc++.h>
using namespace std;

long long n,a[5010],s=0,q,t;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin >> n;
    for(int i=0;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        q=max(a[i],a[i+1]);
        t=max(q,a[i+2]);
        if(a[i]+a[i+1]+a[i+2]>t*2)
        {
            s++;
        }
    }
    cout << s;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
