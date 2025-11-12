#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
const int N=1e5+5;
int n;
int a[N][4];
//int S_cmp=1;
struct S{
    int val[4],cur,nxt;
    bool operator<(const S&_1)const{
        return (val[cur]-val[nxt])>(_1.val[_1.cur]-_1.val[_1.nxt]);
    }
};
priority_queue<S> q[4];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        for(int i=1;i<=3;i++)
        while(!q[i].empty()) q[i].pop();
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
        for(int i=1;i<=n;i++){
            S now;
            int max1=-1,max2,nxt1=-1,nxt2;
            for(int j=1;j<=3;j++){
                now.val[j]=a[i][j];
                if(a[i][j]>=max1){nxt1=max1,nxt2=max2,max1=a[i][j],max2=j;}
                else if(a[i][j]>nxt1) nxt1=a[i][j],nxt2=j;
            }
            now.cur=max2,now.nxt=nxt2;
            q[max2].push(now);ans+=max1;
            if(q[max2].size()>(n/2ll)){
                S tmp=q[max2].top();
                q[max2].pop();
                int tmx=tmp.cur;
                tmp.cur=tmp.nxt;
                tmp.nxt=6ll-tmp.cur-tmx;
                q[tmp.cur].push(tmp);
                ans+=tmp.val[tmp.cur]-tmp.val[tmx];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
