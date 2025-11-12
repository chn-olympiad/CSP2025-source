#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct node{
    int id;
    int data;
}mi[N];
int n,a[N][4];
bool cmp(node x,node y){
    return x.data<y.data;
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int flag[4]={0,0,0,0},sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            int mx=max(max(a[i][1],a[i][2]),a[i][3]);
            sum+=mx;
            if(a[i][1]==mx)flag[1]++;
            else if(a[i][2]==mx)flag[2]++;
            else if(a[i][3]==mx)flag[3]++;
        }
        int kl=max(max(flag[1],flag[2]),flag[3]);
        int gkl;
        if(kl<=n/2){
            cout<<sum<<"\n";
            continue;
        }
        if(kl==flag[1])gkl=1;
        if(kl==flag[2])gkl=2;
        if(kl==flag[3])gkl=3;
        for(int i=1;i<=n;i++){
            mi[i].data=-1e17,mi[i].id=i;
            for(int j=1;j<=3;j++){
                if(j==gkl)continue;
                mi[i].data=max(mi[i].data,a[i][j]-a[i][gkl]);
            }
        }
        int ans=0,opt=0;
        sort(mi+1,mi+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(opt<n/2){
                ans+=a[mi[i].id][gkl];
                opt++;
            }else{
                int mp=-1e17;
                for(int j=1;j<=3;j++){
                    if(j==gkl)continue;
                    mp=max(mp,a[mi[i].id][j]);
                }
                ans+=mp;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
