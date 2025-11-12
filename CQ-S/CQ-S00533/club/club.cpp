#include<bits/stdc++.h>
using namespace std;
// inline long long read(){
//     long long x=0,w=0;
//     char c=0;
//     while(c<'0'||c>'9'){
//         w|=c=='-';
//         c=getchar();
//     }
//     while(c>='0'&&c<='9'){
//         x=(x<<3)+(x<<1)+(c^48);
//         c=getchar();
//     }
//     return w?-x:x;
// }
int T;
int n;
int a[3][100050],ans,cnt;
priority_queue<int> q;
vector<int> id[3];
inline void solve(){
    scanf("%d",&n);
    id[0].clear();
    id[1].clear();
    id[2].clear();
    while(!q.empty()){
        q.pop();
    }
    ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&a[j][i]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            if(a[j][i]>=a[(j+1)%3][i]&&a[j][i]>=a[(j+2)%3][i]){
                ans+=a[j][i];
                id[j].push_back(i);
                break; 
            }
        }
    }
    for(int j=0;j<3;j++){
        if((int)id[j].size()>n/2){
            cnt=(int)id[j].size()-n/2;
            for(int i:id[j]){
                q.push(max(a[(j+1)%3][i],a[(j+2)%3][i])-a[j][i]);
            }
            for(int i=1;i<=cnt;i++){
                ans+=q.top();
                q.pop();
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}
