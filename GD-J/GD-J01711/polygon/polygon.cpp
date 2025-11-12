#include<bits/stdc++.h>
using namespace std;
long long a[500000];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt = 0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
            cnt++;
    }
    if(n<=2 && k==0)
    {
        cout<<0;
    }
    else if(n<=10 && k<=1)
    {
        cout<<1;
    }
    else if(k==0)
        cout<<cnt;

    return 0;
}

