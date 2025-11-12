#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n,k,ans,a[N],b[N];
int f(int l,int r){
    if(l==r){
        return a[l];
    }
    return b[r]^b[l-1];
}
void dfs(int x,int s){
    if(x>n){
        return ;
    }
    for(int i=x;i<=n;i++){
        for(int j=i;j<=n;j++){//"int j=x" /fn /fn
            if(f(i,j)==k){
                dfs(j+1,s+1);
            }
        }
    }
    ans=max(ans,s);
}
bool check(){
    if(k>1){
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]>1){
            return 0;
        }
    }
    return 1;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //x^y==(x|y)-(x&y) Useless!!!
    //a[l]^a[l+1]...^a[r-1]^a[r]=b[r]^b[l-1]
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        b[i]^=b[i-1];
    }
    if(check()||n>100){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(f(i,j)==k){
                    ans++;
                    i=j;
                    break;
                }
            }
        }
    }
    else{
        dfs(1,0);
    }
    cout<<ans;
    return 0;
}
