#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N=100005;
PII a[N][4];
priority_queue<int>q[4];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=3;i++) q[i]=q[0];
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            scanf("%d",&a[i][j].first);
            a[i][j].second=j;
        }
        sort(a[i]+1,a[i]+4);
        res+=a[i][3].first;
        q[a[i][3].second].push(a[i][2].first-a[i][3].first);
    }
    int mid=(n/2);
    for(int i=1;i<=3;i++){
        while(q[i].size()>mid){
            res+=q[i].top();
            q[i].pop();
        }
    }
    printf("%d\n",res);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(;t;--t) solve();
}