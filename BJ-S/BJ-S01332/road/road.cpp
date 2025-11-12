#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k,a[N][N],c[20],tmp[N],b[20];
long long ans;
struct node{
    int x,y;
};
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(a,0x3f,sizeof(a));
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=a[y][x]=min(a[x][y],min(a[y][x],z));
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        queue<node>q;
        long long sum=0;
        for(int j=1;j<=n;j++){
            cin>>tmp[j];
            for(int w=1;w<j;w++){
                if(tmp[w]+tmp[j]+c[i]<=a[j][w]){
                    a[j][w]=a[w][j]=tmp[w]+tmp[j],b[i]=1;
                }
                else if(tmp[w]+tmp[j]<=a[j][w]){
                    if(b[i]==1){
                        a[j][w]=a[w][j]=tmp[w]+tmp[j];
                    }else{
                        q.push({j,w});
                        sum+=a[j][w]-tmp[w]-tmp[j];
                    }
                }
            }
        }
        if(b[i]==1||sum>c[i]){
            b[i]=1;
            while(!q.empty()){
                int t1=q.front().x,t2=q.front().y;
                a[t1][t2]=a[t2][t1]=tmp[t1]+tmp[t2];
            }
            ans+=c[i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans+=a[i][j];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
