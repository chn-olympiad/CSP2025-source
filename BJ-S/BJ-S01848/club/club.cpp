#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int t,n,aa,bb,cc,num[4];
struct stu
{
    int now,nown,next;
}a[N];
void init()
{
    for(int i=1;i<=3;i++)num[i]=0;
    return;
}
int maxn(int a,int b,int c)
{
    return max(a,max(b,c));
}
int nmaxn(int a,int b,int c)
{
    return max(min(a,b),max(min(a,c),min(b,c)));
}
int which(int a,int b,int c,int d)
{
    if(d==a)return 1;
    if(d==b)return 2;
    if(d==c)return 3;
    return 0;
}
bool cmp(int a,int b){  return a>b;}
bool cmp2(stu a,stu b)
{
    return a.next<b.next;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        init();
        cin>>n;
        ll ans=0;
        int numm=-1,numb=0;
        for(int i=1;i<=n;i++)
        {
            cin>>aa>>bb>>cc;
            a[i].now=maxn(aa,bb,cc);
            ans+=a[i].now;
            a[i].next=maxn(aa,bb,cc)-nmaxn(aa,bb,cc);
            a[i].nown=which(aa,bb,cc,a[i].now);
            num[a[i].nown]++;
            if(num[a[i].nown]>numm)numm=num[a[i].nown],numb=a[i].nown;
        }
        if(numm<=n/2)cout<<ans<<"\n";
        else
        {
            sort(a+1,a+n+1,cmp2);
            for(int i=1;i<=n;i++)
            {
                if(a[i].nown==numb)ans-=a[i].next,numm--;
                if(numm<=n/2)break;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
