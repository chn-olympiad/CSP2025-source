#include<bits/stdc++.h>
#define N 100005
#define pii pair<int,int>
using namespace std;
int t,n,a[N][4],ans;
int read()
{
    int k=0,f=1;
    char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        k=k*10+c-'0';
        c=getchar();
    }
    return k*f;
}
bool tp=0;
int tp1[N];
bool cmp(int x,int y)
{
    return x>y;
}
void dfs(int cnt,int a1,int a2,int a3,int sum)
{
    if(cnt==n+1){
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=3;++i) {
        if(a1<n/2) dfs(cnt+1,a1+1,a2,a3,sum+a[cnt][1]);
        if(a2<n/2) dfs(cnt+1,a1,a2+1,a3,sum+a[cnt][2]);
        if(a3<n/2) dfs(cnt+1,a1,a2,a3+1,sum+a[cnt][3]);
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--){
        n=read();
        ans=0,tp=0;
        for(int i=1;i<=n;++i){
            a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
            if(a[i][2] || a[i][3]) tp=1;
        }
        if(n==2){
            for(int i=1;i<=3;++i){
                for(int j=1;j<=3;++j){
                    if(i==j) continue;
                    ans=max(ans,a[1][i]+a[2][j]);
                }
            }
            cout<<ans<<"\n";
            continue;
        }
        if(!tp){
            for(int i=1;i<=n;++i){
                tp1[i]=a[i][1];
            }
            sort(tp1+1,tp1+n+1,cmp);
            for(int i=1;i<=n/2;++i) ans+=tp1[i];
            cout<<ans<<"\n";
            continue;
        }
        dfs(1,0,0,0,0);
        cout<<ans<<"\n";
    }
    return 0;
}
/*
club
*/