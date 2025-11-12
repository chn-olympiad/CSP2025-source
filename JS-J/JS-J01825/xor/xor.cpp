#include<bits/stdc++.h>
using namespace std;
int n=0,a[600000],maxx=0;
long long k=0;
int nxor(int c,int d)
{
    int num=0,b=1;
    while(c/2==0&&d/2==0)
    {
        if(c%2!=d%2)
        {
           num+=b;
        }
        c%=2;
        d%=2;
        b*=2;
    }
    return num;

}
int test(int be,int c)
{
    int l=0;
    for(int i=be;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]==k)
            {
                c++;
                test(j,c);
                c--;
            }
            if(l==0)
            {
                l=nxor(i,j);
            }
            else
            {
                l=nxor(l,j);
            }
            if(l==k)
            {
                c++;
                test(j,c);
                c--;
            }
        }
        l=0;
    }
    if(maxx<c)
        maxx=c;

}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    test(1,0);
    cout<<maxx;
    return 0;
}
