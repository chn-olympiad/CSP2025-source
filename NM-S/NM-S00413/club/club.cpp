#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    int a,b,c;
}club[100050];
ll ans=0;
int n=0;
int sum[100050];
bool isb,isc;
void dfs(int dis1,int dis2,int dis3,ll an){
    int x=dis1+dis2+dis3;
    if(x==n)ans=max(an,ans);
    int a=club[x+1].a,b=club[x+1].b,c=club[x+1].c;
    if(an+a+sum[n]-sum[x+1]>ans)
        if(dis1<n/2)dfs(dis1+1,dis2,dis3,an+a);
    if(an+b+sum[n]-sum[x+1]>ans)
        if(dis2<n/2)dfs(dis1,dis2+1,dis3,an+b);
    if(an+c+sum[n]-sum[x+1]>ans&&isc)
        if(dis3<n/2)dfs(dis1,dis2,dis3+1,an+c);
}
inline ll read(){
    ll a=0;bool f=0;char p=getchar();
    while(!isdigit(p)){f|=p=='-';p=getchar();}
    while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p=getchar();}
    return f?-a:a;
}
void outs(ll x){
    if(x<10){
        putchar(x+'0');
        return ;
    }
    outs(x/10);
    putchar(x%10+'0');
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    t=read();
    while(t--){
        n=read();
        isb=0,isc=0;
        for(register int i=1;i<=n;++i)club[i].a=read(),club[i].b=read(),club[i].c=read(),isb|=club[i].b,isc|=club[i].c,sum[i]=sum[i-1]+max(club[i].a,max(club[i].b,club[i].c));;
        ans=0;

        if(n>=30)ans=sum[n-2];
        if(!isb){
            cout<<sum[n/2]<<endl;
            continue;
        }
        dfs(0,0,0,0);
        outs(ans);
        puts(" ");
    }
    return 0;
}
