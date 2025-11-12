#include<cstdio>
#include<algorithm>
using namespace std;
int n,ay[505],sum,ans;
int bj[505],jl[505];
void to_do(int i){
    if (ay[jl[i-1]-1]*2<sum) {
        ans++;
    }
}
void dg(int a,int i,int last){
    if (a>i) {
        to_do(i);
        return ;
    }
    for (int j=last+1;j<=n;j++){
        if (bj[j-1]==1) continue;
        jl[a-1]=j;
        bj[j-1]=1;
        sum+=ay[j-1];
        dg(a+1,i,j);
        bj[j-1]=0;
        sum-=ay[j-1];
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&ay[i]);
    sort(ay,ay+n);
    for (int i=3;i<=n;i++) dg(1,i,0);
    printf("%d",ans);
    return 0;
}
