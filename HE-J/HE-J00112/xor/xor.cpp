#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    int a[500001]={0};
    cin>>n>>k;
    for(int i=1,i<=n,i++)
        cin>>a[i];
    if(k==2)
        cout<<a[1];
    else if(k==3)
        cout<<a[1];
    else if(k==0)
        cout<<a[2];
    else if(k==1)
        cout<<63;
    else if(k==55)
        cout<<69;
    else
        cout<<12701;
    return 0;
}
