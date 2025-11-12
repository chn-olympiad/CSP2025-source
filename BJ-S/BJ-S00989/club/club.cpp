#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;
int a[maxn][4];
priority_queue<int>q1;
priority_queue<int>q2;
priority_queue<int>q3;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--){
        while(!q1.empty()){
            q1.pop();
        }
        while(!q2.empty()){
            q2.pop();
        }
        while(!q3.empty()){
            q3.pop();
        }
        int summ=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            int minn=min(min(a[i][1],a[i][2]),a[i][3]),maxx=max(max(a[i][1],a[i][2]),a[i][3]),tot=a[i][1]+a[i][2]+a[i][3];
            summ+=maxx;
            if(a[i][1]==maxx) q1.push(0-(2*maxx-tot+minn));
            else if(a[i][2]==maxx) q2.push(0-(2*maxx-tot+minn));
            else q3.push(0-(2*maxx-tot+minn));
        }
        while(q1.size()>(n/2)){
            int cnt=q1.top();
            q1.pop();
            summ+=cnt;
        }
        while(q2.size()>(n/2)){
            int cnt=q2.top();
            q2.pop();
            summ+=cnt;
        }
        while(q3.size()>(n/2)){
            int cnt=q3.top();
            q3.pop();
            summ+=cnt;
        }
        cout<<summ<<endl;
    }
    return 0;
}
