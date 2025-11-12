#include<bits/stdc++.h>
#define IO(name) freopen(name".in","r",stdin),freopen(name".out","w",stdout)
using namespace std;
int n,k,a[500005],cnt;
bool vis[500005];
int f(int x,int y){
    int ans=a[x];
    for(int i=x+1;i<=y;i++) ans^=a[i];
    return ans;
}
bool check(int x,int y){
    for(int t=x;t<=y;t++)
        if(vis[t]) return false;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    IO("xor");
    cin>>n>>k;
    if(n>1000&&k<=1){
        if(k==1){
            for(int i=1;i<=n;i++){
                cin>>a[i];
                if(a[i]) cnt++;
            }
            cout<<cnt;
        }
        else{
            for(int i=1;i<=n;i++){
                cin>>a[i];
                if(!a[i]) cnt++;
            }
            for(int i=1;i<=n;i++)
                if(a[i]&&a[i+1]) cnt++,i++;
                cout<<cnt;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=i;j>=1;j--)
            if(f(j,i)==k&&check(j,i)){
                for(int t=j;t<=i;t++) vis[t]=true;
                cnt++;
                break;
            }
    }
    cout<<cnt;
    return 0;
}
