#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n,ans;
int a[N][5],b[N];
int l[5];
void dfs(int i,int sum){
    if(i>n){
        ans=max(ans,sum);
        return;
    }
    if(l[1]<n/2){
        l[1]++;
        dfs(i+1,sum+a[i][1]);
        l[1]--;
    }
    if(l[2]<n/2){
        l[2]++;
        dfs(i+1,sum+a[i][2]);
        l[2]--;
    }
    if(l[3]<n/2){
        l[3]++;
        dfs(i+1,sum+a[i][3]);
        l[3]--;
    }
}

bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        bool f=1;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0||a[i][3]!=0) f=0;
        }
        if(f==1){
            for(int i=1;i<=n;i++){
                b[i]=a[i][1];
            }
            sort(b+1,b+1+n,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=b[i];
            }
            cout<<ans<<'\n';
        }
        else{
            dfs(1,0);
            cout<<ans<<'\n';
        }
    }
    return 0;
}

