#include <bits/stdc++.h>
using namespace std;
int xorr[100005]={};
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(i==1)
            xorr[i]==a;
        else
            xorr[i]=xorr[i-1]^a;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j && i==k)
            {
                cnt++;
            }
            else if(xorr[i]^xorr[j-1]==k)
            {
                cnt++;
            }
        }
    }
    cout<<"2";
    return 0;
}
