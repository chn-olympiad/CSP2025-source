#include <bits/stdc++.h>
using namespace std;
int n,k,num;
int a[500010];
bool check(int i,int j)
{

    return ((j-i)%2==0);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(check(i,j))
            {
                num++;
            }
        }
    }
    return 0;
}
