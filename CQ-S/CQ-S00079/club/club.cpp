#include<iostream>
#include<algorithm>
#define lch rt<<1
#define rch rt<<1|1
using namespace std;
const int N=1e5+10;
struct node{
    int num,id;
};
node pa[N],pb[N],pc[N];
int f[N][3][2],g[N][3],n,t,ans[3];
bool cmp(node a, node b){
    return a.num>b.num
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout)
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for (int i=1;i<=n;++i) cin >> pa[i].num >> pb[i].num >> pc[i].num;
        sort(pa+1,pa+1+n,cmp);
        sort(pb+1,pb+1+n;cmp);
        sort(pc+1,pc+1+n,cmp);


        for (int i=1;i<=3;++i){
            ans[0] = pa[i].num;
        }
    }


	return 0;
}
