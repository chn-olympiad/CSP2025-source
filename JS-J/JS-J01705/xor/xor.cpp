#include<bits/stdc++.h>
#define io freopen("xor.in","r",stdin),freopen("xor.out","w",stdout)
int n,k,ans;
bool isOne=true,isOneOrZero=true;
int a[1000000];
using namespace std;
int main()
{
    io;
    cin>>n>>k;
    //cout<<n<<k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=1){isOne=false;}
        if(a[i]!=0&&a[i]!=1){isOneOrZero=false;break;}
    }
    //cout<<isOneOrZero<<endl;
    if(isOne)cout<<n/2<<endl;
    else if(isOneOrZero)
    {
        if(!k)
        {
            int tmp=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1)ans++;
            }
            ans/=2;
        }
        else{
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1)ans++;
            }
        }
        cout<<ans<<endl;
    }
    else
    {
        int i=0,tmp=0;
        for(;i<n;)
        {
            i++;
            tmp=tmp^a[i];
            //cout<<tmp<<endl;
            if(a[i]==k)
            {
                //cout<<"-----"<<endl;
                tmp=0;
                ans++;
            }
            if(tmp==k)
            {
                //cout<<"tmp==k"<<endl;
                tmp=0;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
