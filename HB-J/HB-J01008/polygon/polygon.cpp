#include <bits/stdc++.h>
using namespace std;
int a[100],n;
long long ans=0;
void dfs(int c,int i,int b,int h){
    if(c==n){
        return;
    }
    c++;
    i++;
    for(;i<n;i++){
        h+=a[i];
        int b2;
        if(a[i]>=b){
            b2=a[i];
        }
        else{
            b2=b;
        }
        if(h>b2*2&&c>2){
            ans++;
            if(ans==998244353){
                ans=0;
            }
        }
        dfs(c,i,b2,h);
        h-=a[i];
    }
}
int main(){
    freopen("polygon.in","w",stdin);
    freopen("polygon.out","r",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    dfs(0,-1,0,0);
    cout << ans;
    return 0;
}
