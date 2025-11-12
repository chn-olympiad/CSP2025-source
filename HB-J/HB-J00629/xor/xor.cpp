#include<bits/stdc++.h>
using namespace std;
int n,k,s[546491],mx,p;
void f(int b,int a)
{
    if(b>n)
    {
        mx=max(mx,a);
        return;
    }
    for(int i=b;i<=n;i++)
    {
        p=s[i]^s[b-1];
        if(p==k)
        {
            f(i+1,a+1);
            break;
        }
    }
    f(b+1,a);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]^=s[i-1];
    }
    f(1,0);
    cout<<mx;
    return 0;
}
