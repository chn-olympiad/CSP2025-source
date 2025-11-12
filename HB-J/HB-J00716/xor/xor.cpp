#include<bits/stdc++.h>
#define byGyf return
using namespace std;
int n,k,a[500005]={0},b[500005]={0};
void replay(int x,int t)
{
    int ws=1;
    while(x!=0)
    {
        b[t]+=ws*(x%2);
        x/=2;
        ws*=10;
    }
}
int xxor(int a,int b)
{
    int ws=1,rt=0;
    while(a!=0&&b!=0)
    {
        rt+=ws*((int)(a%10!=b%10));
        ws*=10;
        a/=10;
        b/=10;
    }
    return rt;
}
int reback(int t)
{
    int ws=1,cnt=0;
    while(t!=0)
    {
        if(t%10==1)
        {
            cnt+=ws;
        }
        ws*=2;
        t/=10;
    }
    return cnt;
}
int plan_a()
{
    int cnt=0;
    int res=1;
    while(res<=n)
    {
        int t=res;
        int sum=b[t];
        int fl=1;
        while(t<n)
        {
            t++;
            sum=xxor(sum,b[t]);
            if(reback(sum)==k)
            {
                res=t+1;
                fl=0;
                break;
            }
        }
        if(fl==1) res++;
    }
}
int plan_b()
{
    int cnt=0;
    int res=1;
    while(1)
    {
        if(a[res]!=a[res+1])
        {
            cnt++;
            res+=2;
            if(res>=n) break;
        }
        else
        {
            res+=1;
            if(res>=n) break;
        }
    }
    return cnt;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int flag=0;
    //cout<<reback(10101)<<"xxx"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        replay(a[i],i);
        if(a[i]!=1) flag=1;
        if(a[i]!=1&&a[i]!=0) flag=2;
    }
    if(flag==0)
    {
        cout<<floor(n/2);
    }
    else if(flag==1)
    {
        cout<<plan_b();
    }
    else
    {
        cout<<plan_a();
    }
    byGyf 0;
}
