#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,inf=0x3f3f3f3f;
typedef long long ll;
struct node{int num,id;};
node a[N][N];
bool cmp(node a,node b){return a.num>b.num;}
bool cxmp(int a,int b){return a>b;}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.in","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
                cin>>a[i][j].num;
        if(n==2){//5pts~
            int ans=0;
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    if(i==j)continue;
                    else ans=max(ans,a[1][i].num+a[2][j].num);
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
