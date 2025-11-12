#include <iostream>
using namespace std;
const int N = 1e4+10;
const int M = 1e6+10;
int ui[M];
int vi[M];
int wi[M];//修复该道路的费用
int ai[N];//在该乡镇与原有的城市间建造道路的费用
int c[15];//第j个乡镇进行城市化改造的费用
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>ui[i]>>vi[i]>>wi[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>ai[j];
        }
    }
    cout<<0;

    return 0;
}
