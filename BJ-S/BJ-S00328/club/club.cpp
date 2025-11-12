#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c,cha=0,choice;
}a[114514];
int suma=0,sumb=0,sumc=0;
long long ans=0;
bool cmp(node x,node y)
{
    return x.cha<y.cha;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        ans=0;
        suma=sumb=sumc=0;
        int n;
        cin >>n;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
            int x=a[i].a,y=a[i].b,z=a[i].c;
            if (x>=y && y>=z)
            {
                ans+=x;
                suma++;
                a[i].cha=x-y;
                a[i].choice=1;
            }
            else if (x>=z && z>=y)
            {
                ans+=x;
                suma++;
                a[i].cha=x-z;
                a[i].choice=1;
            }
            else if (y>=x && x>=z)
            {
                ans+=y;
                sumb++;
                a[i].cha=y-x;
                a[i].choice=2;
            }
            else if (y>=z && x<=z)
            {
                ans+=y;
                sumb++;
                a[i].cha=y-z;
                a[i].choice=2;
            }
            else if (z>=x && x>=y)
            {
                ans+=z;
                sumc++;
                a[i].cha=z-x;
                a[i].choice=3;
            }
            else if (z>=y && x<=y)
            {
                ans+=z;
                sumc++;
                a[i].cha=z-y;
                a[i].choice=3;
            }
        }
        int p=n/2;
        int maxn=max(suma,max(sumb,sumc));
        int maxi=0;
        if (suma>=sumb && suma>=sumc)maxi=1;
        if (sumb>=suma && sumb>=sumc)maxi=2;
        if (sumc>=sumb && sumc>=suma)maxi=3;
        if (maxn<=p)
        {
            cout << ans;
            return 0;
        }
        sort(a+1,a+n+1,cmp);
        int sum=maxn-p;
        for (int i=1;i<=n;i++)
        {
            if (a[i].choice==maxi)
            {
                ans-=a[i].cha;
                sum--;
                if (!sum)break;
            }
        }
        cout << ans <<"\n";
    }
    return 0;
}
