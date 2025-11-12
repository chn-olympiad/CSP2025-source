#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0,a[500050],count1=0,countk=0,count01=0,count00=0;
bool flag1=true,flag0=true;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1) count1++;
        if(a[i]==k) countk++;
        if(a[i]!=1&&a[i]!=0) flag1=false;
        if(a[i]!=0&&a[i]!=1) flag0=false;
    }
    //A:10pts
    if(flag1&&!flag0)
    {
        if(k>1)
        {
            cout<<0;
            return 0;
        }
        else if(k==0)
        {
            cout<<n/2;
            return 0;
        }
        else if(k==1)
        {
            cout<<count1;
            return 0;
        }
    }
    //B:20pts
    else if(flag0&&flag1)
    {
        if(k>1)
        {
            cout<<0;
            return 0;
        }
        else if(k==0)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]^a[i+1]==0)
                {
                    count00++;
                    i+=1;
                }
            }
            cout<<count00;
            return 0;
        }
        else if(k==1)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]^a[i+1]==1)
                {
                    count01++;
                    i+=1;
                }
            }
            cout<<count01;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
