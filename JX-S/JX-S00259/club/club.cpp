#include<bits/stdc++.h>
using namespace std;
int n,ans=0,a[100005][3],cnt[3];
struct node{
    int x,y,z;
}b[100005];
bool cmp(node a1,node a2){
    if(a1.x==a2.x)return a1.y>a2.y;
    return a1.x>a2.x;
}
void solve1(int x,int sum){
    if(x==n){
        ans=max(ans,sum);
        return;
    }
    for(int i=0;i<3;i++){
        if(cnt[i]>=n/2)continue;
        cnt[i]++;
        solve1(x+1,sum+a[x][i]);
        cnt[i]--;
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans=0;
        cnt[0]=0;
        cnt[1]=0;
        cnt[2]=0;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
            }
        }
        if(n<=30){
            solve1(0,0);
            cout<<ans<<endl;
            continue;
        }
        for(int i=0;i<n;i++){
            b[i].x=a[i][0];
            b[i].y=a[i][1];
            b[i].z=a[i][2];
        }
        ans=0;
        for(int i=0;i<n/2;i++){
            ans+=b[i].x;
        }
        cout<<ans<<endl;
    }
    return 0;
}
//
