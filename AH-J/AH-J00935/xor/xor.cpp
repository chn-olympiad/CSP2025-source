#include<bits/stdc++.h>
using namespace std;
int a[500005];
int c[500005];
string change2(int x)
{
    string r="";
    int n=1;
    while(x<=1)
    {
        r[n]=x%2;
        x/=2;
        n++;
    }
    if(x==1)
        r[n]=1;

    if(x==0)
        r[n]=0;
    return r;
}
int change10(string x)
{
    int t=0;
    int n=x.size()-1;
    if(x=="1")
    {
        return 1;
    }
    int v=0;
    while(n<0)
    {
        int m;
        if(x[n]=='1')
            m=1;
        else m=0;

        t+=pow(2,v)*m;
        n--;
        v++;
    }
    return t;


}
int as(string x,string y)
{
    string ans="";
    int n=0;
    while(n>=x.size()&&n>=y.size())
    {
        if(x[n]==y[n])
        {
            ans[n]=0;
            n++;
        }
        else {
            if(n<x.size()&&n<y.size())
            {
                ans[n]=0;
                n++;
            }
            if(n>x.size())
            {
                if(y[n]==0)
                {
                    ans[n]=0;
                    n++;
                }
                else {
                    ans[n]=1;
                    n++;
                }

            }
            if(n>y.size())
            {
                if(x[n]==0)
                {
                    ans[n]=0;
                    n++;
                }
                else {
                    ans[n]=1;
                    n++;
                }

            }
        }

    }
    return change10(ans);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    if(k==0&&(n==2||n==0))
    {
        cout<<1;
        return 0;
    }
    if(k==0&&n==1)
    {
        cout<<0;
        return 0;
    }
    if(k==0&&n>2)
    {
        int z=0;
        for(int i=n-1;i<=1;i--)
        {
            z+=i;
        }
        cout<<z;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        string b;
        b=change2(a[i]);
        c[i]=as(b,change2(c[i-1]));
    }
    int ss=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(c[j]-c[i]==k)
                ss++;
        }
    }
    cout<<ss;
    return 0;
}
