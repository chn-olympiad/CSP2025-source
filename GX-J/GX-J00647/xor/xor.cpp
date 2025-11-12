#include<bits/stdc++.h>
using namespace std;
long long n,k,b,ans;
bool vis[500100];
vector<int> a;
void dfs(int l){
    int su;bool flag=true;
    for(int i=0;i<n;i++){
        if(i+l<=n){
            for(int j=i;j<i+l;j++){
                if(j==i) su = a[j];
                else su = su^a[j];
                if(vis[j]==true){
                    flag = false;break;
                }
            }
            if(su==k&&flag==true){
                for(int j=i;j<i+l;j++){
                    vis[j] = true;
                }
                ans++;
            }
            flag = true;
        }else break;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>b;
        a.push_back(b);
    }
    for(int i=1;i<=n;i++){
        dfs(i);
    }
    cout<<ans;
    return 0;
}
