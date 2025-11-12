#include <iostream>
using namespace std;
int a[500005];
int wangye(int k,int h)
{
    int f=a[k];
    if(k==h)
    {
        return a[k];
    }
    for(int i=k+1;i<=h;i++)
    {
        f=f^a[i];
    }
    return f;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int m,n,shu=0;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=i;j<=m;j++)
        {
            if(wangye(i,j)==n)
            {
                shu++;
                i=j+1;
                j++;
            }
        }
    }
    cout<<shu;
}
