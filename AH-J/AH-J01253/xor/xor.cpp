#include<bits/stdc++.h>
using namespace std;
long long n,i,j,k,s=0,x,w;
string e[500005],t,tt,ans;
struct node{
    long long z;
    bool f;
}a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    if(k==0)
    {
        t="0";
    }
    else
    {
        t="1";
    }
    for(i=1;i<=n;++i)
    {
        cin>>a[i].z;
        if(a[i].z==k)
        {
            s++;
            a[i].f=1;
        }
        else
        {
            if(a[i].z==0)
            {
                e[i]="0";
            }
            else
            {
                e[i]="1";
            }
        }
    }
    if(k==1)
    {
        cout<<s;
        return 0;
    }
    for(x=2;x<=n;++x)
    {
        for(i=1;i<=n-x+1;++i)
        {
            if(a[i].f==1)
            {
                continue;
            }
            bool flag=0;
            ans=e[i];
            for(j=i+1;j<i+x;++j)
            {
                if(a[j].f==1)
                {
                    flag=1;
                    break;
                }
                if(e[j]==ans)
                {
                    ans='0';
                }
                else
                {
                    ans='1';
                }
            }
            if(ans==t&&flag==0)
            {
                s++;
                for(j=i;j<i+x;++j)
                {
                    a[j].f=1;
                }
            }
        }
    }
    cout<<s;
    return 0;
}
