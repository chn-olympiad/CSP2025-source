#include<bits/stdc++.h>
using namespace std;
int n,k,s;
int a[500010],x[500010],y[500010];
int j(int l,int r)
{
    if(l>n&&r>n)return 0;
    else if(r>n)j(l+1,l+1);
    if(l>r)j(l,l);
    else
    {y[r-l+1]=a[l];
        for(int i=l+1;i<=r;i++)
        {
            y[i]=y[i-1]^a[i];
        }
        if(y[r]!=k)
        {
            j(l,r+1);
        }
        else
        {
            s++;j(r+1,r+1);
        }
    }

}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }x[1]=a[1];
    j(1,1);
    cout<<s;
    return 0;
}
