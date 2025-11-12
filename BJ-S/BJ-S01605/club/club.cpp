#include<bits/stdc++.h>
using namespace std;
int n,T,a[10005][5],cnt[5],ans[10001],d[10000001],k=1;
void dfs(int x){
    if(x==n+1){
        for(int i=1;i<x;i++){
            d[k]+=ans[i];
        }
        k++;
        return;
    }
    for(int i=1;i<=3;i++){
        if(cnt[i]>=n/2)continue;
        cnt[i]++;
        ans[x]=a[x][i];
        dfs(x+1);
        cnt[i]--;
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    for(int t=1;t<=T;t++){
        cin >> n;
        for(int i=1;i<=3;i++)cnt[i]=0;
        for(int i=1;i<=k;i++)d[i]=0;
        k=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin >> a[i][j];
            }
        }
        dfs(1);
        int maxx=-1;
        for(int i=1;i<k;i++){
            maxx=max(maxx,d[i]);
        }
        cout << maxx << endl;
    }
    return 0;
}