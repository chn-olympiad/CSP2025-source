#include<bits/stdc++.h>
using namespace std;
long long n,k,l,r,a[500100],ans,temp;
int yihuo(long a1,long a2)
{
    string s1,s2;
    while(a1>0)
    {
        s1+=char(a1%2+48);
        a1/=2;
    }
    while(a2>0)
    {
        s2+=char(a2%2+48);
        a2/=2;
    }
    int L=max(s1.size(),s2.size());
    int sum=0;
    if(L!=s1.size())
    {
        for(int i=s1.size();i<=L;i++)
        {
            s1[i]='0';
        }
    }
    else
    {
        for(int i=s2.size();i<=L;i++)
        {
            s2[i]='0';
        }
    }
    for(int i=L-1;i>=0;i--)
    {
        if(s1[i]!=s2[i])
        {
            sum=sum+pow(2,i);
        }
    }
    return sum;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {

        temp=yihuo(temp,a[i]);
        if(temp==k)
        {
            ans++;
            temp=0;
        }
    }
    cout<<ans;

    return 0;
}
