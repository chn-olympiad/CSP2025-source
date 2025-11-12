#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
//int a[maxn],b[maxn],c[maxn];
int vis[maxn][8];
int cnt[maxn];
//int viss[maxn];
int sum,dl,n;
//struct club{
    //int a,b,c;
//}p[maxn];
int a[maxn][8];
//bool cmp(club e1,club e2){
    //return e1.a>e2.a;
//}
int bsum = 0;
int aa=0,bb=0,cc=0;
void dfs(int now1,int now2){
    cout << cnt[now1-1] << " ";
    if(vis[now1][now2] || now1>n){
        return;
    }
    //cout << cnt[n] <<" ";
    vis[now1][now2] = 1;
    if(now2==1){
        aa++;
        if(aa>dl){
            aa--;
            dfs(now1,now2+1);
            vis[now1][now2] = 0;
        }
        else{

            bsum += a[now1][now2];
            cnt[now1] = max(cnt[now1],cnt[now1-1]+bsum);
            bsum -= a[now1][now2];
            //aa--;
            dfs(now1,now2+1);
            //dfs(now1+1,1);
            aa--;
            vis[now1][now2] = 0;

        }
        //dfs(now1,now2+1);
        //aa--;
    }
    else if(now2==2){
        bb++;
        if(bb>dl){
            bb--;
            dfs(now1,now2+1);
            vis[now1][now2] = 0;
        }
        else{

            bsum += a[now1][now2];
            cnt[now1] = max(cnt[now1],cnt[now1-1]+bsum);
            bsum -= a[now1][now2];
            //bb--;
            dfs(now1,now2+1);
            //dfs(now1+1,1);
            bb--;
            vis[now1][now2] = 0;

        }
        //dfs(now1,now2+1);
        //bb--;
    }
    else if(now2==3){
        cc++;
        if(cc>dl){
            cc--;
            dfs(now1+1,1);
            vis[now1][now2] = 0;
        }
        else{

            bsum += a[now1][now2];
            cnt[now1] = max(cnt[now1],cnt[now1-1]+bsum);
            bsum -= a[now1][now2];
            //cc--;
            dfs(now1+1,1);
            cc--;
            vis[now1][now2] = 0;

        }
        //dfs(now1,now2+1);

    }
    //dfs(now1,now2+1);
    //vis[now1][now2] = 0;

    return ;
}
int main(){
    freopen("club1.in","r",stdin);
    freopen("club1.out","w",stdout);
    int t;
    cin >> t;

    for(int i=1;i<=t;i++){
        memset(cnt,0,sizeof(cnt));
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        //memset(viss,0,sizeof(viss));
        //memset(c,0,sizeof(c));
        aa=0,bb=0,cc=0;
        cin >> n;
        sum = 0;
        dl = n/2;
        for(int j=1;j<=n;j++){
            int x,y,z;
            cin>>x>>y>>z;
            a[j][1] = x;
            a[j][2] = y;
            a[j][3] = z;
        }
        //sort(p+1,p+n+1,cmp);
        //for(int j=1;j<=n;j++){
            //if(!vis[j][])

        //}
        dfs(1,1);
        for(int j=1;j<=n;j++){
            cout <<cnt[j]<<" ";
        }
        cout << cnt[n] << endl;
    }
    return 0;
}
