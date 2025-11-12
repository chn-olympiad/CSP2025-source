#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,a[N+5][5],p[N+5][5],ct[5];
priority_queue<int> q[5];
void tmain(){
    int ans=0;
    while(!q[0].empty())q[0].pop();
    while(!q[1].empty())q[1].pop();
    while(!q[2].empty())q[2].pop();
    cin>>n;ct[0]=ct[1]=ct[2]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        p[i][0]=0,p[i][1]=1,p[i][2]=2;
        sort(p[i],p[i]+3,[i](int x,int y){return a[i][x]>a[i][y];});
        ct[p[i][0]]++;
        q[p[i][0]].push(a[i][p[i][1]]-a[i][p[i][0]]);
        ans+=a[i][p[i][0]];
    }
    while(ct[0]>n/2){ans+=q[0].top();q[0].pop();ct[0]--;}
    while(ct[1]>n/2){ans+=q[1].top();q[1].pop();ct[1]--;}
    while(ct[2]>n/2){ans+=q[2].top();q[2].pop();ct[2]--;}
    cout<<ans<<'\n';
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)tmain();
}