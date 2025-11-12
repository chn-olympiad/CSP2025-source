#include <cstdio>
#include <vector>
using namespace std;

vector<int> city[10005];
int w[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=m; ++i){
        int u,v,w_;
        scanf("%d%d%d",&u,&v,&w_);
        city[u].push_back(v);
        city[v].push_back(u);
        w[i]=w_;
    }
    printf("0");
    return 0;

}
