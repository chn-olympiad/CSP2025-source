#include <bits/stdc++.h>
using namespace std;
#define LL long long
int n,m;
string s;
int c[505];
int cnt,ans;
bool f[505];
int a[505];
void dfs(int w){
    if(w==n){
        cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'&&i-cnt<c[a[i]]){
                cnt++;
            }
        }
        if(cnt==m){
            ans++;
        }
        return;
    }
    for(int i=0;i<n;i++){
        if(f[i]==0){
            a[w]=i;
            f[i]=1;
            dfs(w+1);
            f[i]=0;
        }
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    if(n<=10){
        dfs(0);
        cout<<ans;
        return 0;
    }
    return 0;
}
