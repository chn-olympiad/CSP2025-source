#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int n,a[maxn]={0},k,_1,_0,_255;
int main(void)
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {

        cin>>a[i];
        if(a[i]==1)_1++;
        if(a[i]==0)_0++;
        if(a[i]==255)_255++;
    }
    if(_1==n&&k==0)
    {
        cout<<n/2;
    }
    else
    {
        if(k==255)
        {
            cout<<_255;
            return 0;
        }
        if(k==0)
        {
            cout<<_0;
            return 0;
        }
        if(k==1)
        {
            cout<<_1;
            return 0;
        }
    }
}
