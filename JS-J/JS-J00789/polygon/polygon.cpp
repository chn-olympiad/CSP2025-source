#include<iostream>
#define P 998244353
using namespace std;
int a[5001];
int n;
int cnt=0;
void dfs(int mx,int ms,int ta){
    if(ms>(mx*2))cnt++;
    for(int i=ta;i<n;i++){
        dfs(max(mx,a[i]),ms+a[i],i+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int mx=0,sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        sum+=a[i];
    }
    if(n==3){
        if(sum>(mx*2)){
            cout<<1;
        }
        else cout<<0;
    }
    else{
        dfs(0,0,0);
        cout<<cnt;
    }
    return 0;
}
