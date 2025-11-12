#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main()
{    
    int s1=0,s2=0;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++)
    {
        s1=s1 xor a[i];
        if(s1==k)
        {
            for(int j=i+1;j<n;j++)
            {
                s2= s2 xor a[j];
                if(s2==k)
                {
                    cout<<1;
                    return 0;
                }
            }
        }
    }
    cout<<0;
    return 0;
}                          