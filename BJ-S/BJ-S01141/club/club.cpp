#include<bits/stdc++.h>
#define int long long
using namespace std;

int t,n,ans,cnt1,cnt2;
struct node{
    int a,b,c;
}ax[100010];

int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'&&ch>'9')ch=getchar();
    while(ch<='9'&&ch>='0'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}

void dfs(int step,int sum,int x,int y,int z){
    if(x>n/2||y>n/2||z>n/2)return;
    if(step==n+1){
        ans=max(ans,sum);
        return;
    }
    dfs(step+1,sum+ax[step].a,x+1,y,z);
    dfs(step+1,sum+ax[step].b,x,y+1,z);
    dfs(step+1,sum+ax[step].c,x,y,z+1);
}

bool cmp(node x,node y){
    return x.a>y.a;
}

bool cmp2(node x,node y){
    return x.a-x.b>y.a-y.b;
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--){
        n=read();
        ans=0,cnt1=0,cnt2=0;
        bool f=1;
        for(int i=1;i<=n;i++){
            ax[i].a=read();
            ax[i].b=read();
            ax[i].c=read();
            if(ax[i].b==0)cnt1++;
            if(ax[i].c==0)cnt2++;
            if(ax[i].a!=0&&ax[i].a!=20000)f=0;
            if(ax[i].b!=0&&ax[i].b!=20000)f=0;
            if(ax[i].c!=0&&ax[i].c!=20000)f=0;
        }
        if(cnt1==n&&cnt2==n){
            sort(ax+1,ax+n+1,cmp);
            for(int i=1;i<=n/2;i++)ans+=ax[i].a;
        }else if(f==1){
            int p=0,q=0,z=0;
            for(int i=1;i<=n;i++){
                int xx=0;
                if(ax[i].a&&p<n/2)xx=1;
                if(ax[i].b&&q<n/2){
                    if(!xx)xx=2;
                    else if(p>q)xx=2;
                }
                if(ax[i].c&&z<n/2){
                    if(!xx)xx=3;
                    if(xx==1&&p>z)xx=3;
                    if(xx==2&&q>z)xx=3;
                }
                if(xx)ans+=20000;
                if(xx==1)p++;
                if(xx==2)q++;
                if(xx=3)z++;
            }
        }else if(cnt2==n){
            sort(ax+1,ax+n+1,cmp2);
            int p=0,q=0,z=0;
            for(int i=1;i<=n/2;i++)ans+=ax[i].a;
            for(int i=n/2+1;i<=n;i++)ans+=ax[i].b;
        }else dfs(1,0,0,0,0);
        printf("%lld\n",ans);
    }
}
