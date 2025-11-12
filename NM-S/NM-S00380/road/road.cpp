#include<bits/stdc++.h>
using namespace std;
struct nude{
    int l;
    int r;
}road[1000050];
int r[1000050];
int con[15];
int ci[100050];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int m,n,k,num=0;
    int ans=0;
    cin>>n>>m>>k;
    for(int i=i;i<=m;i++){
        cin>>road[i].l>>road[i].r>>r[i];
    }
    long long a[k][n];
    for(int i=1;i<=k;i++){
        cin>>con[i];
        if(con[i]==0){
            num++;
        }
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(num==0){
        for(int i=1;i<=m;i++){
            if(ci[road[i].r]!=-1){
                ans+=r[i];
                ci[road[i].r]=-1;
                ci[road[i].l]=-1;
                continue;
            }
            if(ci[road[i].l]!=-1){
                ans+=r[i];
                ci[road[i].r]=-1;
                ci[road[i].l]=-1;
                continue;
            }
        }
        cout<<ans;
    }
    if(num!=0){
        for(int i=1;i<=k;i++){
            if(con[i]==0){
                for(int j=1;j<=n;j++){
                    if(a[i][j]==0){
                        ci[j]=-1;
                        continue;
                    }
                }
            }
        }
       for(int i=1;i<=m;i++){
            if(ci[road[i].r]!=-1){
                ans+=r[i];
                ci[road[i].r]=-1;
                ci[road[i].l]=-1;
                continue;
            }
            if(ci[road[i].l]!=-1){
                ans+=r[i];
                ci[road[i].r]=-1;
                ci[road[i].l]=-1;
                continue;
            }
        }
        cout<<ans;
    }
    return 0;
}
