#include <bits/stdc++.h>
#define int long long
#define gc getchar_unlocked
int read(){
    int x=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c))x=x*10+c-'0',c=gc();
    return f?-x:x;
}
using namespace std;
const int dd=2e5+5;
const int M=1e9+7;
int a[dd][3];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int T=read();
    while(T--){
        memset(a,0,sizeof(a));
        int n=read();
        for(int i=1;i<=n;i++)
            for(int j=0;j<=2;j++)
                a[i][j]=read();
        vector<int>c[3];
        vector<int>cnt(3);int ans=0;
        for(int i=1;i<=n;i++){
            int now=-1,mx=-1,ls=-1;
            for(int j=0;j<3;j++){
                if(a[i][j]>mx){
                    mx=a[i][j];
                    now=j;
                }
            }ans+=mx;
            for(int j=0;j<3;j++){
                if(j!=now){
                    ls=max(ls,a[i][j]);
                }
            }
            cnt[now]++;c[now].push_back(mx-ls);
        }
        for(int j=0;j<3;j++){
            if(cnt[j]>n/2){
                int dx=cnt[j]-n/2;
                sort(c[j].begin(),c[j].end());
                for(int i=0;i<dx;i++)
                    ans-=c[j][i];
            }
        }
        printf("%lld\n",ans);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
