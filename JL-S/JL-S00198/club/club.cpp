#include <bits/stdc++.h>
using namespace std;
int t;
int n;
struct node
{
    int val1;
    int val2;
    int val3;
    int id;
};
node a[100005];
node f1[100005];
node f2[100005];
node f3[100005];
int cnt1=0;
int cnt2=0;
int cnt3=0;
int ans=0;
bool cmp1(node x,node y)
{
    if(x.val1==y.val1)
    {
        if(x.val2==y.val2)
        {
            return x.val3>y.val3;
        }
        else
            return x.val2>y.val2;
    }
    else
    {
        return x.val1>y.val1;
    }
}
bool cmp2(node x,node y)
{
    if(x.val2==y.val2)
    {
        if(x.val1==y.val1)
        {
            return x.val3>y.val3;
        }
        else
            return x.val1>y.val1;
    }
    else
        return x.val2>y.val2;
}
bool cmp3(node x,node y)
{
    if(x.val3==y.val3)
    {
        if(x.val1==y.val1)
        {
            return x.val2>y.val2;
        }
        else
            return x.val1>y.val1;
    }
    else
        return x.val3>y.val3;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f1));
        memset(f3,0,sizeof(f3));
        memset(a,0,sizeof(a));
        cnt1=0;
        cnt2=0;
        cnt3=0;
        int cnt4=0,flag=0;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].val1>>a[i].val2>>a[i].val3;
            if(a[i].val2==0 && a[i].val3==0)
            {
                cnt4++;
            }
            a[i].id=i;
        }
        if(n==2)
        {
            ans=max(a[1].val1+a[2].val2,max(a[1].val1+a[2].val3,max(a[1].val2+a[2].val1,max(a[1].val2+a[2].val3,max(a[1].val3+a[2].val1,a[1].val3+a[2].val2)))));
            cout<<ans<<endl;
            flag=1;
        }
        else if(cnt4==n)
        {
            sort(a+1,a+n+1,cmp1);
            for(int i=1;i<=n/2;i++)
            {
                ans+=a[i].val1;
            }
            cout<<ans<<endl;
            flag=1;
        }
        for(int i=1;i<=n;i++)
        {
            int fmax=max(a[i].val1,max(a[i].val2,a[i].val3));
            if(fmax==a[i].val1)
                cnt1++,f1[cnt1].id=i,f1[cnt1].val1=a[i].val1,f1[cnt1].val2=a[i].val2,f1[cnt1].val3=a[i].val3;
            else if(fmax==a[i].val2)
                cnt2++,f2[cnt2].id=i,f2[cnt2].val1=a[i].val1,f2[cnt2].val2=a[i].val2,f2[cnt2].val3=a[i].val3;
            else
                cnt3++,f3[cnt3].id=i,f3[cnt3].val1=a[i].val1,f3[cnt3].val2=a[i].val2,f3[cnt3].val3=a[i].val3;
        }
        if(cnt1>n/2)
        {
            sort(f1+1,f1+cnt1+1,cmp1);

            for(int i=n/2;i<=cnt1;i++)
            {
                if(f1[i].val2>f1[i].val3 && cnt2<n/2)
                {
                    cnt2++;
                    f2[cnt2].val1=f1[i].val1;
                    f2[cnt2].val2=f1[i].val2;
                    f2[cnt2].val3=f1[i].val3;
                    f2[cnt2].id=f1[i].id;
                    cnt1--;
                }
                else
                {
                    cnt3++;
                    f3[cnt3].val1=f1[i].val1;
                    f3[cnt3].val2=f1[i].val2;
                    f3[cnt3].val3=f1[i].val3;
                    f3[cnt3].id=f1[i].id;
                    cnt1--;
                }
            }
        }
        else if(cnt2>n/2)
        {
            sort(f2+1,f2+cnt2+1,cmp2);
            for(int i=n/2;i<=cnt2;i++)
            {
                if(f2[i].val1>f1[i].val3 && cnt1<n/2)
                {
                    cnt1++;
                    f1[cnt1].val1=f2[i].val1;
                    f1[cnt1].val2=f2[i].val2;
                    f1[cnt1].val3=f2[i].val3;
                    f1[cnt1].id=f2[i].id;
                    cnt2--;
                }
                else
                {
                    cnt3++;
                    f3[cnt3].val1=f2[i].val1;
                    f3[cnt3].val2=f2[i].val2;
                    f3[cnt3].val3=f2[i].val3;
                    f3[cnt3].id=f2[i].id;
                    cnt2--;
                }
            }
        }
        else
        {
            sort(f3+1,f3+cnt3+1,cmp3);
            for(int i=n/2;i<=cnt3;i++)
            {
                if(f3[i].val1>f3[i].val2 && cnt1<n/2)
                {
                    cnt1++;
                    f1[cnt1].val1=f3[i].val1;
                    f1[cnt1].val2=f3[i].val2;
                    f1[cnt1].val3=f3[i].val3;
                    f1[cnt1].id=f3[i].id;
                    cnt3--;
                }
                else
                {
                    cnt2++;
                    f2[cnt2].val1=f3[i].val1;
                    f2[cnt2].val2=f3[i].val2;
                    f2[cnt2].val3=f3[i].val3;
                    f2[cnt2].id=f3[i].id;
                    cnt3--;
                }
            }
        }
        for(int i=1;i<=cnt1;i++)
        {
            ans+=f1[i].val1;
        }
        for(int i=1;i<=cnt2;i++)
        {
            ans+=f2[i].val2;
        }
        for(int i=1;i<=cnt3;i++)
        {
            ans+=f3[i].val3;
        }
        if(flag==0)
            cout<<ans<<endl;

    }
}
