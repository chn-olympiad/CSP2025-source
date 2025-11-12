#include<bits/stdc++.h>
using namespace std;
int a[4][100005];
int ch[100005];
/*struct intint{
    int cc;
    int ii;
};ch[100005];
int cmp(intint a,intint b)
{
    return a.cc<=a.ii;
}*/
int max2(int i)
{
    if(max(a[1][i],a[2][i])<=a[3][i])
    {
        return max(a[1][i],a[2][i]);
    }
    else if(a[1][i]>a[3][i]&&a[2][i]>a[3][i])
    {
        return min(a[1][i],a[2][i]);
    }
    else
        return a[3][i];

}
int maxmark(int i,int maxi)
{
    for(int j=1;j<=3;j++)
    {
        if(a[j][i]==maxi)return j;
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    long long ans=0;
    priority_queue<int> co1;
    priority_queue<int> co2;
    priority_queue<int> co3;
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(ch,0,sizeof(ch));
        ans=0;
        while(co1.size())co1.pop();
        while(co2.size())co2.pop();
        while(co3.size())co3.pop();
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
            int maxi=max(a[1][i],max(a[2][i],a[3][i]));
            ch[i]=maxi-max2(i);
            //ch[i].ii=i;
            int mk=maxmark(i,maxi);
            ans+=maxi;
            if(mk==1)co1.push(-ch[i]);
            else if(mk==2)co2.push(-ch[i]);
            else co3.push(-ch[i]);
        }
        int m=n/2;
        while(co1.size()>m)
        {
            ans+=co1.top();
            co1.pop();
        }
        while(co2.size()>m)
        {
            ans+=co2.top();
            co2.pop();
        }
        while(co3.size()>m)
        {
            ans+=co3.top();
            co3.pop();
        }
        printf("%lld\n",ans);
    }
}

