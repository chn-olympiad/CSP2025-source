#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,e,r,ans=0,out;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;// n为城市总数 m为道路总数 k为乡镇总数
    int a[n+1][n+1]={0};
    for(int i=1;i<=m;i++){
        cin >> u >> v >> w;
        a[u][v]=w;// 表示城市u与城市v之间的修路费用为v
        a[v][u]=w;
    }
    int b[k+1][n+1]={0};//第k个乡镇和第n个城市的道路费用
    int d[k+1]={0};//第k个乡镇的建造费用
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin >> d[i] >>b[i][j];
            b[j][i]=b[i][j];
        }
    }

    int num = a[1][1];
    for(int i=1;i<=n;i++){//城市之间的路的最小值
        for(int j=1;j<=n;j++){
            if(num>a[i][j]&&a[i][j]!=0){
                num=a[i][j];
                u=i;  v=j;
            }
        }
    }
    a[u][v]=0; ans+=num;
    for(int i=1;i<=n;i++){//城市之间的路的第二小
        for(int j=1;j<=n;j++){
            if(num>a[i][j]&&a[i][j]!=0){
                num=a[i][j];
                w=i,e=j;
            }
        }
    }
    ans+=num;


    num=d[1];
    for(int i=2;i<=k;i++){//最便宜的乡镇
        if(num>d[i]&&d[i]!=0){
            num=d[i];
            r=i;
        }
    }
    ans += num;

    int y;
    for(int i=1;i<=n;i++){
        if(i!=u&&i!=v&&i!=w&&i!=e){
            y=i;
        }
    }
    ans += b[y][r];
    b[y][r]=0;
    num=b[1][1];
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(num>b[i][j]&&b[i][j]!=0){
                num=b[i][j];
            }
        }
    }
    ans+= num;
    cout << ans << endl;

    return 0;
}
