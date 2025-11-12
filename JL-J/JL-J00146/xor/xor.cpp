#include<bits/stdc++.h>
using namespace std;
int n,k,s=0,a[100005],b[100005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)b[i]=0;
        else if(a[i]==1)b[i]=1;
        else if(a[i]==2)b[i]=2;
        else if(a[i]==3)b[i]=1;
        else b[i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]==k)s++;
        else if(b[i]+b[i+1]==k)
        {
            s++;
        }
        else if(b[i]+b[i+1]+b[i+2]==k)
        {
            s++;
        }
        else if(b[i]+b[i+1]+b[i+2]+b[i+3]==k)
        {
            s++;
        }
    }
    cout<<s;
    return 0;
}
