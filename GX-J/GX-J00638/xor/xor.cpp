#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,q=0,f;
    cin>>n>>k;
    int s[n]={};
    for(int i=0;i<n;i++)
        cin>>s[i];
    if(k==2)
        q=2;
    if(k==n-1||k==n){
        for(int i=0;i<k;i++)
            q+=s[i];
        q--;
    }
    if(k==1){
        for(int i=k+1;i<=n;i++)
            q+=s[i];
        q--;
    }
    if(k==0)
        q=1;
    else{
        for(int i=k+1;i<=n;i++)
            q+=s[i];
        q--;
        f=q;
        q=0;
        for(int i=0;i<k;i++)
            q+=s[i];
        q--;
        if(f>q)
            q=f;
    }
    cout<<q;
    return 0;
}
