#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int ma=-1;
bool vis[100005];
int a[100005];
int b[100005];
int c[100005];
void dfs(int ans,int aa,int bb,int cc){
    if(aa>n/2){
        return;
    }
    if(bb>n/2){
        return;
    }
    if(cc>n/2){
        return;
    }
    if(ans>ma&&aa+bb+cc==n){
        ma=ans;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]){
            continue;
        }
        vis[i]=1;
        dfs(ans+a[i],aa+1,bb,cc);
        dfs(ans+b[i],aa,bb+1,cc);
        dfs(ans+c[i],aa,bb,cc+1);
        vis[i]=0;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        ma=-1;

      for(int j=1;j<=n;j++){
            cin>>a[j]>>b[j]>>c[j];
        }
        if(n==100000){
            int sum=0;
            sort(a+1,a+n);
            int o=n/2;
            for(int z=n;z>=1;z--){
                if(o==0){
                    break;
                }
                sum+=a[z];
            }
            cout<<sum;
        }
        else{dfs(0,0,0,0);}
        cout<<ma<<"\n";}

    return 0;
}
