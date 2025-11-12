#include<bits/stdc++.h>
using namespace std;
int n,k;
int sum;
int ans1;
int ans0;
bool iff=true;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>sum;
        if(sum==1)
        {
            ans1++;
        }
        if(sum==0)
        {
            ans0++;
            iff=true;
        }
    }
    if(iff)
    {
        if(k==1)
        {
            cout<<ans1<<endl;
        }
        else
        {
            cout<<ans0<<endl;
        }
    }
    else
    {
        cout<<ans1<<endl;
    }
    return 0;
}
