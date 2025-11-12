#include<bits/stdc++.h>
using namespace std;
struct ren{
    int a,b,c;
}rp[100005];
int n;
int cnta,cntb,cntc;
int maxn1;

int dx(int num1,int num2,int num3)
{
    if(num1>num2 && num1>num3 && cnta<=n/2)
    {
        cnta++;
        return num1;
    }
    else if(num2>num1 && num2>num3 && cntb<=n/2)
    {
        cntb++;
        return num2;
    }
    else if(num3>num1 && num3>num2 && cntc<=n/2)
    {
        cntc++;
        return num3;
    }
    maxn1=max(num1,max(num2,num3));
    return 1;
}
int dy(int num1,int num2,int num3)
{
    if(maxn1==num2 && num1>num3 && cnta<=n/2)//num2,1
    {
        cnta++;
        return num1;
    }
    else if(maxn1==num2 && num3>num1 && cntc<=n/2)//num2,2
    {
        cntc++;
        return num3;
    }
    else if(maxn1==num3 && num2>num1 && cntb<=n/2)//num3,1
    {
        cntb++;
        return num2;
    }
    else if(maxn1==num3 && num1>num2 && cnta<=n/2)//num3,2
    {
        cnta++;
        return num1;
    }
    else if(maxn1==num1 && num3>num2 && cntc<=n/2)//num1,1
    {
        cntc++;
        return num3;
    }
    else if(maxn1==num1 && num2>num3 && cntb<=n/2)//num1,2
    {
        cntb++;
        return num2;
    }
    return 1;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        long long ans=0;
        int maxn=0,t;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>rp[i].a>>rp[i].b>>rp[i].c;
            maxn=dx(rp[i].a,rp[i].b,rp[i].c);
            if(maxn=1)
            {
                maxn=dy(rp[i].a,rp[i].b,rp[i].c);
            }
            if(maxn=1)
            {
                maxn=max(rp[i].a,max(rp[i].b,rp[i].c));
            }
            ans+=maxn;
        }
        cout<<ans<<"\n";
    }

    return 0;
}

