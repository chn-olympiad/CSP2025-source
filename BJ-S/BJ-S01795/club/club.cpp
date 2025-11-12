#include<bits/stdc++.h>
using namespace std;
struct club
{
    int e, f, g, nn;
}a[100005];
bool cmp1(club d, club p)
{
    if (d.e!=p.e)
        return d.e<p.e;
    else if (d.f!=p.f)
        return d.f<p.f;
    return d.f<p.f;
}
bool cmp2(club d, club p)
{
    if (d.e!=p.e)
        return d.e>p.e;
    else if (d.f!=p.f)
        return d.f>p.f;
    return d.f>p.f;
}
bool cmp3(club d, club p)
{
    if (d.f!=p.f)
        return d.f>p.f;
    else if (d.e!=p.e)
        return d.e>p.e;
    return d.g>p.g;
}
bool cmp4(club d, club p)
{
    if (d.f!=p.f)
        return d.f<p.f;
    else if (d.e!=p.e)
        return d.e<p.e;
    return d.g<p.g;
}
bool cmp5(club d, club p)
{
    if (d.g!=p.g)
        return d.g>p.g;
    else if (d.e!=p.e)
        return d.e>p.e;
    return d.f>p.f;
}
bool cmp6(club d, club p)
{
    if (d.g!=p.g)
        return d.g<p.g;
    else if (d.e!=p.e)
        return d.e<p.e;
    return d.f<p.f;
}
bool cmp7(club d, club p)
{
    if (d.e!=p.e)
        return d.e>p.e;
    else if (d.g!=p.g)
        return d.g>p.g;
    return d.f>p.f;
}
bool cmp8(club d, club p)
{
    if (d.e!=p.e)
        return d.e<p.e;
    else if (d.g!=p.g)
        return d.g<p.g;
    return d.f<p.f;
}
bool cmp9(club d, club p)
{
    if (d.f!=p.f)
        return d.f>p.f;
    else if (d.g!=p.g)
        return d.g>p.g;
    return d.e>p.e;
}
bool cmp10(club d, club p)
{
    if (d.f!=p.f)
        return d.f<p.f;
    else if (d.g!=p.g)
        return d.g<p.g;
    return d.e<p.e;
}
bool cmp11(club d, club p)
{
    if (d.g!=p.g)
        return d.g>p.g;
    else if (d.f!=p.f)
        return d.f>p.f;
    return d.e>p.e;
}
bool cmp12(club d, club p)
{
    if (d.g!=p.g)
        return d.g<p.g;
    else if (d.f!=p.f)
        return d.f<p.f;
    return d.e<p.e;
}
int main()
{
   int t;
   freopen("club.in", "r", stdin);
   freopen("club.out", "w", stdout);
   cin >> t;
   for (int ff=1;ff<=t;ff++)
   {
       int n;
       cin >> n;
       for (int i=1;i<=n;i++)
       {
           cin >> a[i].e >> a[i].f >> a[i].g;
       }
       sort(a+1, a+n+1, cmp1);
       int ans=0, aaa=0;
       int n1=0, n2=0, n3=0;
       for (int i=1;i<=n;i++)
       {
           if (a[i].e==max(max(a[i].e, a[i].f), a[i].g)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else if (a[i].f==max(a[i].f, a[i].g)&&n2<n/2)
           {
               n2++;
               aaa+=a[i].f;
           }
           else if (n3<n/2)
           {
               n3++;
               aaa+=a[i].g;
           }
           else if (a[i].e==max(a[i].e, a[i].f)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else
           {
               n2++;
               aaa+=a[i].f;
           }
       }
       ans=max(aaa, ans);
       n1=0;
       n2=0;
       n3=0;
       aaa=0;
       sort(a+1, a+n+1, cmp2);
       for (int i=1;i<=n;i++)
       {
           if (a[i].e==max(max(a[i].e, a[i].f), a[i].g)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else if (a[i].f==max(a[i].f, a[i].g)&&n2<n/2)
           {
               n2++;
               aaa+=a[i].f;
           }
           else if (n3<n/2)
           {
               n3++;
               aaa+=a[i].g;
           }
           else if (a[i].e==max(a[i].e, a[i].f)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else
           {
               n2++;
               aaa+=a[i].f;
           }
       }
       ans=max(aaa, ans);
       n1=0;
       n2=0;
       n3=0;
       aaa=0;
       sort(a+1, a+n+1, cmp3);
       for (int i=1;i<=n;i++)
       {
           if (a[i].e==max(max(a[i].e, a[i].f), a[i].g)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else if (a[i].f==max(a[i].f, a[i].g)&&n2<n/2)
           {
               n2++;
               aaa+=a[i].f;
           }
           else if (n3<n/2)
           {
               n3++;
               aaa+=a[i].g;
           }
           else if (a[i].e==max(a[i].e, a[i].f)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else
           {
               n2++;
               aaa+=a[i].f;
           }
       }
       ans=max(aaa, ans);
       n1=0;
       n2=0;
       n3=0;
       aaa=0;
       sort(a+1, a+n+1, cmp4);
       for (int i=1;i<=n;i++)
       {
           if (a[i].e==max(max(a[i].e, a[i].f), a[i].g)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else if (a[i].f==max(a[i].f, a[i].g)&&n2<n/2)
           {
               n2++;
               aaa+=a[i].f;
           }
           else if (n3<n/2)
           {
               n3++;
               aaa+=a[i].g;
           }
           else if (a[i].e==max(a[i].e, a[i].f)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else
           {
               n2++;
               aaa+=a[i].f;
           }
       }
       ans=max(aaa, ans);
       n1=0;
       n2=0;
       n3=0;
       aaa=0;
       sort(a+1, a+n+1, cmp5);
       for (int i=1;i<=n;i++)
       {
           if (a[i].e==max(max(a[i].e, a[i].f), a[i].g)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else if (a[i].f==max(a[i].f, a[i].g)&&n2<n/2)
           {
               n2++;
               aaa+=a[i].f;
           }
           else if (n3<n/2)
           {
               n3++;
               aaa+=a[i].g;
           }
           else if (a[i].e==max(a[i].e, a[i].f)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else
           {
               n2++;
               aaa+=a[i].f;
           }
       }
       ans=max(aaa, ans);
       n1=0;
       n2=0;
       n3=0;
       aaa=0;
       sort(a+1, a+n+1, cmp6);
       for (int i=1;i<=n;i++)
       {
           if (a[i].e==max(max(a[i].e, a[i].f), a[i].g)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else if (a[i].f==max(a[i].f, a[i].g)&&n2<n/2)
           {
               n2++;
               aaa+=a[i].f;
           }
           else if (n3<n/2)
           {
               n3++;
               aaa+=a[i].g;
           }
           else if (a[i].e==max(a[i].e, a[i].f)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else
           {
               n2++;
               aaa+=a[i].f;
           }
       }
       ans=max(aaa, ans);
       n1=0;
       n2=0;
       n3=0;
       aaa=0;
       sort(a+1, a+n+1, cmp7);
       for (int i=1;i<=n;i++)
       {
           if (a[i].e==max(max(a[i].e, a[i].f), a[i].g)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else if (a[i].f==max(a[i].f, a[i].g)&&n2<n/2)
           {
               n2++;
               aaa+=a[i].f;
           }
           else if (n3<n/2)
           {
               n3++;
               aaa+=a[i].g;
           }
           else if (a[i].e==max(a[i].e, a[i].f)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else
           {
               n2++;
               aaa+=a[i].f;
           }
       }
       ans=max(aaa, ans);
       n1=0;
       n2=0;
       n3=0;
       aaa=0;
       sort(a+1, a+n+1, cmp8);
       for (int i=1;i<=n;i++)
       {
           if (a[i].e==max(max(a[i].e, a[i].f), a[i].g)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else if (a[i].f==max(a[i].f, a[i].g)&&n2<n/2)
           {
               n2++;
               aaa+=a[i].f;
           }
           else if (n3<n/2)
           {
               n3++;
               aaa+=a[i].g;
           }
           else if (a[i].e==max(a[i].e, a[i].f)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else
           {
               n2++;
               aaa+=a[i].f;
           }
       }
       ans=max(aaa, ans);
       n1=0;
       n2=0;
       n3=0;
       aaa=0;
       sort(a+1, a+n+1, cmp9);
       for (int i=1;i<=n;i++)
       {
           if (a[i].e==max(max(a[i].e, a[i].f), a[i].g)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else if (a[i].f==max(a[i].f, a[i].g)&&n2<n/2)
           {
               n2++;
               aaa+=a[i].f;
           }
           else if (n3<n/2)
           {
               n3++;
               aaa+=a[i].g;
           }
           else if (a[i].e==max(a[i].e, a[i].f)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else
           {
               n2++;
               aaa+=a[i].f;
           }
       }
       ans=max(aaa, ans);
       n1=0;
       n2=0;
       n3=0;
       aaa=0;
       sort(a+1, a+n+1, cmp10);
       for (int i=1;i<=n;i++)
       {
           if (a[i].e==max(max(a[i].e, a[i].f), a[i].g)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else if (a[i].f==max(a[i].f, a[i].g)&&n2<n/2)
           {
               n2++;
               aaa+=a[i].f;
           }
           else if (n3<n/2)
           {
               n3++;
               aaa+=a[i].g;
           }
           else if (a[i].e==max(a[i].e, a[i].f)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else
           {
               n2++;
               aaa+=a[i].f;
           }
       }
       ans=max(aaa, ans);
       n1=0;
       n2=0;
       n3=0;
       aaa=0;
       sort(a+1, a+n+1, cmp11);
       for (int i=1;i<=n;i++)
       {
           if (a[i].e==max(max(a[i].e, a[i].f), a[i].g)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else if (a[i].f==max(a[i].f, a[i].g)&&n2<n/2)
           {
               n2++;
               aaa+=a[i].f;
           }
           else if (n3<n/2)
           {
               n3++;
               aaa+=a[i].g;
           }
           else if (a[i].e==max(a[i].e, a[i].f)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else
           {
               n2++;
               aaa+=a[i].f;
           }
       }
       ans=max(aaa, ans);
       n1=0;
       n2=0;
       n3=0;
       aaa=0;
       sort(a+1, a+n+1, cmp12);
       for (int i=1;i<=n;i++)
       {
           if (a[i].e==max(max(a[i].e, a[i].f), a[i].g)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else if (a[i].f==max(a[i].f, a[i].g)&&n2<n/2)
           {
               n2++;
               aaa+=a[i].f;
           }
           else if (n3<n/2)
           {
               n3++;
               aaa+=a[i].g;
           }
           else if (a[i].e==max(a[i].e, a[i].f)&&n1<n/2)
           {
               n1++;
               aaa+=a[i].e;
           }
           else
           {
               n2++;
               aaa+=a[i].f;
           }
       }
       ans=max(aaa, ans);
       cout << ans << '\n';
   }
   return 0;
}
