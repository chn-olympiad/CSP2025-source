#include<bits/stdc++.h>
using namespace std;
long long n,k,x,s;
long long a[1000005];
bool b[1000005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1) x++;
    }
    for(int i=1;i<=n;i++)
    {
        b[i]=false;
    }
    if(k==1)
    {
        cout<<x;
    }
    if(k==0)
    {
        for(int i=1;i<n;i++)
        {
            if((a[i]==a[i+1])&&(b[i]==false)&&(b[i+1]==false))
            {
                b[i]=true;
                b[i+1]=true;
                s++;
            }
        }
        cout<<s;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
