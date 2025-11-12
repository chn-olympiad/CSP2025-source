#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n;
int a[N][3];
int chk(int x){
    if(a[x][0]>=a[x][1]&&a[x][0]>=a[x][2])
        return 0;
    if(a[x][1]>=a[x][0]&&a[x][1]>=a[x][2])
        return 1;
    return 2;
}
int chs[N];
int cnt[3];
int ans=0;
priority_queue<int>q;
void solve(int x){
    for(int i=1;i<=n;i++){
        if(chs[i]==x){
            int maxx=-0x3f3f3f3f;
            for(int j:{0,1,2}){
                if(j==x)
                    continue;
                maxx=max(maxx,a[i][j]-a[i][x]);
            }
            q.push(maxx);
        }
    }
    int cntt=cnt[x]-n/2;
    while(cntt--){
        ans+=q.top();
        q.pop();
    }
    while(!q.empty())
        q.pop();
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        cnt[0]=cnt[1]=cnt[2]=0;
        for(int i=1;i<=n;i++)
            for(int j:{0,1,2})
                cin>>a[i][j];
        ans=0;
        for(int i=1;i<=n;i++){
            chs[i]=chk(i);
            cnt[chs[i]]++;
            ans+=a[i][chs[i]];
        }
        if(cnt[0]>n/2)
            solve(0);
        if(cnt[1]>n/2)
            solve(1);
        if(cnt[2]>n/2)
            solve(2);
        cout<<ans<<'\n';
    }
    return 0;
}
