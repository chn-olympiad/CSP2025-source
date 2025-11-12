#include <bits/stdc++.h>

using namespace std;
int flag[100005];
struct unit{
    int bg;
    int nd;
    int cst;
}road[1000005];
bool cmp(unit a,unit b){
    return a.cst<b.cst;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>road[i].bg>>road[i].nd>>road[i].cst;
    }
    sort(road+1,road+n+1,cmp);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(flag[road[i].bg]==0||flag[road[i].nd]==0){
            cnt+=road[i].cst;
            flag[road[i].bg]=1;
            flag[road[i].nd]=1;
//            for(int i=1;i<=30;i++){
//                cout<<flag[i];
//            }
//            cout<<endl;
        }
    }
    cout<<cnt;
    return 0;
}
