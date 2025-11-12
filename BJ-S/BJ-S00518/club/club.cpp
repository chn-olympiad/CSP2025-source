#include<iostream>
#include<queue>
using namespace std;

const int maxn=1e5+5;

int t,n;
int ans;
int a[maxn][5];

priority_queue<int>q[5];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)cin>>a[i][j];
        for(int i=1;i<=n;i++){
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                q[1].push(max(a[i][2],a[i][3])-a[i][1]);
                ans+=a[i][1];
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
                q[2].push(max(a[i][1],a[i][3])-a[i][2]);
                ans+=a[i][2];
            }
            else{
                q[3].push(max(a[i][1],a[i][2])-a[i][3]);
                ans+=a[i][3];
            }
        }
        for(int i=1;i<=3;i++)
            while(q[i].size()>n/2)ans+=q[i].top(),q[i].pop();
        cout<<ans<<'\n';
        for(int i=1;i<=3;i++)
            while(q[i].size())q[i].pop();
    }
    return 0;
}
