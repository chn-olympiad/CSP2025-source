#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][3],ans,T,k[N][3],cnt[3];
priority_queue<int>q;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        memset(cnt,0,sizeof cnt);
        while(q.size())q.pop();
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            k[i][0]=min(min(a[i][0],a[i][1]),a[i][2]);
            k[i][2]=max(max(a[i][0],a[i][1]),a[i][2]);
            k[i][1]=a[i][0]+a[i][1]+a[i][2]-k[i][0]-k[i][2];
            for(int j=0;j<3;j++)
                if(a[i][j]==k[i][2])
                    k[i][0]=j;
            cnt[k[i][0]]++;
            k[i][1]=k[i][2]-k[i][1];
            ans+=a[i][k[i][0]];
        }
        for(int i=0;i<3;i++){
            if(cnt[i]>(n>>1)){
                for(int j=1;j<=n;j++){
                    if(k[j][0]==i){
                        q.push(-k[j][1]);
                    }
                }
                for(;cnt[i]>(n>>1);cnt[i]--){
                    ans+=q.top();
                    q.pop();
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}