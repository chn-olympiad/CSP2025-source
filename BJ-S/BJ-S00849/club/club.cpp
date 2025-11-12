#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int T,n,p[4][maxn],l[4],p2[maxn],ans = 0;
struct op{
    int a[5],fi,se;
}ji[maxn];
bool cmp(int x,int y){
    if(ji[x].a[ji[x].fi] - ji[x].a[ji[x].se] != ji[y].a[ji[y].fi] - ji[y].a[ji[y].se])return ji[x].a[ji[x].fi] - ji[x].a[ji[x].se] > ji[y].a[ji[y].fi] - ji[y].a[ji[y].se];
    return ji[x].a[ji[x].fi] <ji[y].a[ji[y].fi];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= 3 ; j++){
                cin>>ji[i].a[j];
            }
            if(ji[i].a[1] >= ji[i].a[2] && ji[i].a[2] >= ji[i].a[3]){
                ji[i].fi = 1;
                ji[i].se = 2;
            }
            if(ji[i].a[1] >= ji[i].a[3] && ji[i].a[3] >= ji[i].a[2]){
                ji[i].fi = 1;
                ji[i].se = 3;
            }
            if(ji[i].a[2] >= ji[i].a[1] && ji[i].a[1] >= ji[i].a[3]){
                ji[i].fi = 2;
                ji[i].se = 1;
            }
            if(ji[i].a[2] >= ji[i].a[3] && ji[i].a[3] >= ji[i].a[1]){
                ji[i].fi = 2;
                ji[i].se = 3;
            }
            if(ji[i].a[3] >= ji[i].a[2] && ji[i].a[2] >= ji[i].a[1]){
                ji[i].fi = 3;
                ji[i].se = 2;
            }
            if(ji[i].a[3] >= ji[i].a[1] && ji[i].a[1] >= ji[i].a[2]){
                ji[i].fi = 3;
                ji[i].se = 1;
            }
        }
        for(int i = 1 ; i <= n ; i++){
            p[ji[i].fi][++l[ji[i].fi]] = i;
            ans += ji[i].a[ji[i].fi];
        }
        for(int i = 1 ; i <= 3 ; i++){
            if(l[i] <= n/2)continue;
            else{
                for(int j = 1 ; j <= l[i] ; j++){
                    p2[j] = p[i][j];
                }
                sort(p2+1,p2+l[i]+1,cmp);
                for(int j = n/2+1 ; j <= l[i] ; j++){
                    ans -= ji[p2[j]].a[ji[p2[j]].fi];
                    ans += ji[p2[j]].a[ji[p2[j]].se];
                }
            }
        }
        cout<<ans<<endl;
        memset(p,0,sizeof(p));
        memset(l,0,sizeof(l));
        memset(p2,0,sizeof(p2));
        ans = 0;
    }
    return 0;
}
