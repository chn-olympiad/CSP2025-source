#include<iostream>
using namespace std;
int n,m,k;
const int N=1e4+7;
int a[N][N]={};
void f(int u){

}
long long sum=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(a[u][v]==0){
            a[u][v]=a[v][u]=w;
            sum+=w;
        }else if(w<a[u][v]){    //quchong
            a[u][v]=a[v][u]=w;
            sum+=w;
        }
    }
        printf("%lld",sum);
}
