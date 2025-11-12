#include<bits/stdc++.h>
using namespace std;
const int N=18;
int n,m,p[N],arr[N];
long long res;
char s[N];
bool vis[N];
void dfs(int k){
    if(k>n){
        int bai=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(bai>=p[arr[i]]){
                bai++;
                continue;
            }
            if(s[i-1]=='1')cnt++;
            else bai++;
        }
        if(cnt>=m)res++;
    }
    else{
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vis[i]=1;
                arr[k]=i;
                dfs(k+1);
                arr[k]=0;
                vis[i]=0;
            }
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)cin>>p[i];
    int er=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1')er++;
    }
    if(er<m){
        cout<<0;
        return 0;
    }
    dfs(1);
    cout<<res;
    return 0;
}