#include<bits/stdc++.h>
using namespace std;
#define N 5005
#define ll long long
int n;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
ll ans=0;
void f(int ij,int k,int mx,int add){
    if(ij>n){
        if(add>=3&&k>mx*2){
            ans++;
        }
        return ;
    }
    f(ij+1,k,mx,add);
    f(ij+1,k+a[ij],max(mx,a[ij]),add+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int add=0;
    bool o=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            o=false;
        }
    }
    if(o==true&&n>20){
        for(int i=3;i<=n;i++){
            ll u=1,v=1;
            for(int j=1;j<=i;j++){
                u*=j;v*=(n-j+1);
            }
            ans+=(v/u);
        }
        cout<<ans;
        return 0;
    }
    f(1,0,-1,0);
    cout<<ans;
    return 0;
}
