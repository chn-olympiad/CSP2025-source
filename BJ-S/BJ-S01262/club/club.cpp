#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct club{
    int a,b,c,bigg,f;
}g[maxn];
club vis[maxn];
int n,t,cnt1=0,cnt2=0,cnt3=0,ans=0;
bool cmp(club a,club b){return a.bigg<b.bigg;}

/*
void dfs(int x,int cnt1,int cnt2,int cnt3,int cnt){
    if(x==n+1&&cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
        ans=max(ans,cnt);
        return;
    }

    if(cnt1+1<=n/2) dfs(x+1,cnt1+1,cnt2,cnt3,cnt+a[x][1]);
    if(cnt2+1<=n/2) dfs(x+1,cnt1,cnt2+1,cnt3,cnt+a[x][2]);
    if(cnt3+1<=n/2) dfs(x+1,cnt1,cnt2,cnt3+1,cnt+a[x][3]);

    return;
}

int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];

            }
        }
        dfs(1,0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;

}
*/


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>g[i].a>>g[i].b>>g[i].c;
        }
        for(int i=1;i<=n;i++){
            int x=max(g[i].a,max(g[i].b,g[i].c));
            if(x==g[i].a){vis[i].a=1;g[i].f=1;}
            else if(x==g[i].b){vis[i].b=1;g[i].f=2;}
            else if(x==g[i].c){vis[i].c=1;g[i].f=3;}

            g[i].bigg=x;
        }
        sort(g+1,g+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(g[i].f==1) cnt1++;
            if(g[i].f==2) cnt2++;
            if(g[i].f==3) cnt3++;
        }
        if(cnt1>n/2){
            int sum=1;
            while(sum<=cnt1-n/2){
                if(g[sum].b<=g[sum].c){
                    g[sum].bigg=g[sum].c;


                } else if(g[sum].b>g[sum].c){
                    g[sum].bigg=g[sum].b;
                    g[sum].f=2;

                }
                sum++;
            }
        }
        if(cnt2>n/2){
            int sum=1;
            while(sum<=cnt2-n/2){
                if(g[sum].a<=g[sum].c){
                    g[sum].bigg=g[sum].c;
                    g[sum].f=3;

                } else if(g[sum].a>g[sum].c){
                    g[sum].bigg=g[sum].a;
                    g[sum].f=2;

                }
                sum++;
            }
        }
        if(cnt3>n/2){
            int sum=1;
            while(sum<=cnt3-n/2){
                if(g[sum].a<=g[sum].b){
                    g[sum].bigg=g[sum].b;
                    g[sum].f=3;

                } else if(g[sum].a>g[sum].b){
                    g[sum].bigg=g[sum].a;
                    g[sum].f=2;

                }
                sum++;
            }
        }
        for(int i=1;i<=n;i++) ans+=g[i].bigg;
        cout<<ans<<endl;

    }
    return 0;

}
