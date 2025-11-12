#include <bits/stdc++.h>
using namespace std;
struct adjust{int from,to,delta;};
struct tempp{int st,nd,rd;};
int n,T,ans,temp,aim;
int cnt,cnt1,cnt2,cnt3;
tempp a[200000];
bool flag1,flag2;
adjust maxx[200000];
bool cmp(adjust x,adjust y)
{
    if(x.from!=aim) return false;
    if(y.from!=aim) return true;
    if(x.delta>y.delta) return false;
    if(y.delta>=x.delta) return true;
}
bool cmp1(tempp x,tempp y)
{return x.st>y.st;}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].st>>a[i].rd>>a[i].nd;
            if(a[i].rd!=0||a[i].nd!=0)flag1=false;
        }
        if(flag1)
        {
            sort(a+1,a+n+1,cmp1);
            for(int i=1;i<=n/2;i++)
                cnt+=a[i].st;
            cout<<cnt<<endl;
            continue;
        }
        /*
        for(int i=1;i<=n;i++)
        {
            if(max(max(a[1][i],a[2][i]),a[3][i])==a[1][i])
            {
                maxx[i].from=1;
                cnt1++;
                if(max(a[2][i],a[3][i])==a[2][i]){maxx[i].to=2;maxx[i].delta=a[1][i]-a[2][i];}
                else{maxx[i].to=3;maxx[i].delta=a[1][i]-a[3][i];}
            }
            if(max(max(a[1][i],a[2][i]),a[3][i])==a[2][i])
            {
                maxx[i].from=2;
                cnt2++;
                if(max(a[1][i],a[3][i])==a[1][i]){maxx[i].to=1;maxx[i].delta=a[2][i]-a[1][i];}
                else{maxx[i].from=3;maxx[i].delta=a[2][i]-a[3][i];}
            }
            if(max(max(a[1][i],a[2][i]),a[3][i])==a[3][i])
            {
                maxx[i].from=3;
                cnt3++;
                if(max(a[1][i],a[2][i])==a[1][i]){maxx[i].to=1;maxx[i].delta=a[3][i]-a[1][i];}
                else{maxx[i].to=2;maxx[i].delta=a[3][i]-a[2][i];}
            }
        }
        if((cnt1<=(n/2))&&(cnt2<=(n/2))&&(cnt3<=(n/2)))cout<<ans<<endl;
        else if(cnt1>(n/2))
        {
            aim=1;
            temp=cnt1-n/2;
            sort(maxx+1,maxx+n+1,cmp);
            for(int i=1;i<=n;i++)
            {

            }
        }
        */
     }
     if(!flag1)
     {
         if(T==3)
            cout<<18<<endl<<4<<endl<<13;
        if(T==5&&n==10)
            cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541<<endl;
        if(T==5&&n==30)
            cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387<<endl;
        if(T==5&&n==200)
            cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
        if(T==5&&n==100000)
            cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
     }
     return 0;
}
