#include<bits/stdc++.h>
using namespace std;
int w[10004][10004],n,m,k,c[10][1000006],d[15],minway=1e9,flag[1000005];
void find(int now,int num,int tot){
    if(num==n){
        minway=min(minway,tot);
        return;
    }
    for(int i=1;i<=n;i++){
        if(flag[i]==1||i==now)continue;
        flag[i]=1;

        find(i,num+1,tot+w[now][i]);
        flag[i]=0;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(w,127,sizeof(w));
    memset(flag,0,sizeof(flag));
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        w[a][b]=c;
        w[b][a]=c;
    }
    for(int i=1;i<=k;i++){
        cin>>d[i];
        for(int j=1;j<=n;j++){
            scanf("%d",&c[i][j]);
            for(int k=1;k<j;k++){
                w[j][k]=min(w[j][k],c[i][j]+c[i][k]);
                w[k][j]=w[j][k];
            }
        }
    }
    flag[1]=1;
    find(1,1,0);
    cout<<minway<<endl;
    return 0;
}
