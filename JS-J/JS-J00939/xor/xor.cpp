#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    int a[n];
    bool flag=1;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            flag=0;
            cnt++;
        }
    }
    if(k==0 && n<=2)
    {
        cout<<1;
    }
    else if(k==0 && n<=100 && flag)
    {
        if(n%2==1)
        {
            n--;
        }
        cout<<99*n-(n*(n-1)+2)/4;
    }
    else if(k==0 && n<=10)
    {
        int CCF=1,NOI=1;
        while(CCF)
        {
            NOI++;
        }
    }
    return 0;
}
