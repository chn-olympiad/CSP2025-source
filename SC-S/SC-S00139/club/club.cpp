#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int arr[3][maxn],id[maxn];
int buck[3],ans;
void solve(){
    int n;
    scanf("%d",&n);
    buck[0]=buck[1]=buck[2]=0;
    ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&arr[0][i],&arr[1][i],&arr[2][i]);
        if(arr[0][i]>=max(arr[1][i],arr[2][i])) id[i]=0;
        else if(arr[1][i]>=max(arr[0][i],arr[2][i])) id[i]=1;
        else id[i]=2;
        buck[id[i]]++,ans+=arr[id[i]][i];
    }
    int pos=-1;
    for(int p=0;p<3;p++){
        if(buck[p]>n/2) pos=p;
    }
  //    fprintf(stderr,"qwq\n");
    if(pos>=0){
        vector<int> res;
        for(int i=1;i<=n;i++){
            if(id[i]==pos){
                int mx=-0x3f3f3f3f;
                for(int p=0;p<3;p++){
                    if(id[i]!=p) mx=max(mx,arr[p][i]);
                }
                res.push_back(arr[id[i]][i]-mx);
            }
        }
        sort(res.begin(),res.end());
        for(int i=0;i<buck[pos]-n/2;i++){
            ans-=res[i];
        }
    }
    printf("%d\n",ans);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}