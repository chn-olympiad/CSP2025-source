#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T,n,ans,op,cnt1,cnt2,cnt3,cnt,a[N][5],vis[N];
priority_queue<int> q;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n,ans=op=cnt1=cnt2=cnt3=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>=max(a[i][2],a[i][3]))cnt1++,vis[i]=1,ans+=a[i][1];
            else{
                if(a[i][2]>=a[i][3])cnt2++,vis[i]=2,ans+=a[i][2];
                else cnt3++,vis[i]=3,ans+=a[i][3];
            }
        }
        if(cnt1>n/2)op=1,cnt=cnt1-n/2;
        if(cnt2>n/2)op=2,cnt=cnt2-n/2;
        if(cnt3>n/2)op=3,cnt=cnt3-n/2;
        if(op==0){
            cout<<ans<<"\n";
            continue;
        }
        if(op!=1)for(int i=1;i<=n;i++)swap(a[i][1],a[i][op]);
        for(int i=1;i<=n;i++)if(vis[i]==op)q.push(max(a[i][2],a[i][3])-a[i][1]);
        while(cnt--)op=q.top(),q.pop(),ans+=op;
        while(!q.empty())q.pop();
        cout<<ans<<"\n";
    }
    return 0;
}