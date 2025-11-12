#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,num=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)    cin>>a[i];
    if(k==0)
    {
        for(int i=0;i<n;i++)
        {
            if(i>0&&a[i-1]==1&&a[i]==1)
            {
                num++;
            }
            else    if(a[i]==0) num++;
        }
    }
    else
    {
        for(int i=0;i<n;i++)    if(a[i]==1) num++;
    }
    cout<<num;
    return 0;
}
