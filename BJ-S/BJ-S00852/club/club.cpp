#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+7;
int t,n;
int a[N][4],rk[N][4],rkbel[N];
ll ans;
struct node{
    int val,id;
    friend bool operator < (const node &a,const node &b){
        return a.val<b.val;
    }
};
priority_queue<node,vector<node>,less<node>>q[4];
inline void init(){
    for(int i=1;i<=3;i++){
        while(!q[i].empty())q[i].pop();
    }
    for(int i=1;i<=n;i++){
        rkbel[i]=0;
        for(int j=1;j<=3;j++)rk[i][j]=0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        int lim=n/2;
        init();
        for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
        for(int i=1;i<=n;i++){
            int x=1,y=2,z=3;
            if(a[i][x]<a[i][y])swap(x,y);
            if(a[i][x]<a[i][z])swap(x,z);
            if(a[i][y]<a[i][z])swap(y,z);
            rk[i][1]=x;
            rk[i][2]=y;
            rk[i][3]=z;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){//第几想去
                if((int)q[rk[i][j]].size()<lim){
                    ans+=a[i][rk[i][j]];
                    rkbel[i]=j;
                    q[rk[i][j]].push((node){a[i][rk[i][j+1]]-a[i][rk[i][j]],i});
                    break;
                }else{
                    if(a[i][rk[i][j]]+q[rk[i][j]].top().val>a[i][rk[i][j+1]]){
                        ans+=a[i][rk[i][j]]+q[rk[i][j]].top().val;
                        int tt=q[rk[i][j]].top().id;
                        q[rk[i][j]].pop();
                        q[rk[i][j]].push((node){a[i][rk[i][j+1]]-a[i][rk[i][j]],i});
                        ++rkbel[tt];
                        rkbel[i]=j;
                        q[rk[tt][rkbel[tt]]].push((node){a[i][rk[tt][rkbel[tt]]]-a[i][rk[tt][rkbel[tt]-1]],tt});//!
                        break;
                    }
                }
                assert(j!=3);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}