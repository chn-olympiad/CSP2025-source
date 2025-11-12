#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct node{
    long long a,b,c;
    long long max1,double1,min1;
    long long cnt;
}a[100010];
long long q[10];
int check1(int i)
{
    if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
    {
        return 1;
    }
    else if(a[i].a<a[i].b&&a[i].b>=a[i].c)
    {
        return 2;
    }
    else{
        return 3;
    }
}
int check2(int i)
{
    if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
    {
        if(a[i].b>=a[i].c)
        {
            return 2;
        }
        else{
            return 3;
        }
    }
    else if(a[i].a<a[i].b&&a[i].b>=a[i].c)
    {
        if(a[i].a>=a[i].c)
        {
            return 1;
        }
        else{
            return 3;
        }
    }
    else{
        if(a[i].a>=a[i].b)
        {
            return 1;
        }
        else{
            return 2;
        }
    }
}
int check3(int i)
{
     if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
    {
        if(a[i].b>=a[i].c)
        {
            return 3;
        }
        else{
            return 2;
        }
    }
    else if(a[i].a<a[i].b&&a[i].b>=a[i].c)
    {
        if(a[i].a>=a[i].c)
        {
            return 3;
        }
        else{
            return 1;
        }
    }
    else{
        if(a[i].a>=a[i].b)
        {
            return 2;
        }
        else{
            return 1;
        }
    }
}
bool cmp(node x,node y)
{
    if(x.max1<y.max1)
    {
        return 1;
    }
    else if(x.max1==y.max1)
    {
        if(x.max1==1)
        {
            return x.a>=y.a;
        }
        else if(x.max1==2)
        {
            return x.b>=y.b;
        }
        else{
            return x.c>=y.c;
        }
    }
}
int check4(node x)
{
    if(x.double1==1)
    {
        return x.a;
    }
    if(x.double1==2)
    {
        return x.b;
    }
    else{
        return x.c;
    }
}
int hwh(node x,node y)
{
    long long cnt1=x.a+y.b;
    long long cnt2=x.a+y.c;
    long long cnt3=x.b+y.a;
    long long cnt4=x.b+y.c;
    long long cnt5=x.c+y.a;
    long long cnt6=x.c+y.b;
    return max(cnt1,max(cnt2,max(cnt3,max(cnt4,max(cnt5,cnt6)))));
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long sum=0;
        cin>>n;
        memset(q,0,sizeof(0));
        memset(a,0,sizeof(0));
        q[1]=n/2,q[2]=n/2,q[3]=n/2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a>>a[i].b>>a[i].c;
            a[i].max1=check1(i);
            a[i].double1=check2(i);
            a[i].min1=check3(i);
           // a[i].cnt=check4(i);
        }
        sort(a+1,a+n+1,cmp);
        if(n==1)
        {
            sum=max(a[1].a,max(a[1].b,a[1].c));
        }
        else if(n==2)
        {
            sum=hwh(a[1],a[2]);
        }
        else{
            for(int i=1;i<=n;i++)
            {
                if(q[a[i].max1]!=0)
                {
                    q[a[i].max1]--;
                    a[i].cnt=max(a[i].a,max(a[i].b,a[i].c));
                }
                else if(q[a[i].max1]==0&&q[a[i].double1]!=0)
                {
                    q[a[i].double1]--;
                    a[i].cnt=check4(a[i]);
                }
                else{
                    q[a[i].min1]--;
                    a[i].cnt=min(a[i].a,min(a[i].b,a[i].c));
                }
                sum+=a[i].cnt;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
