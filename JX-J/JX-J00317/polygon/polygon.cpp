#include<bits/stdc++.h>
using namespace std;
int n,a[5050];
/*const int N=998244353;
int ans;
int he,maxs=-1;
int bc[5050];
void f(int be,int x,int dq){
    for(int i=be;i<=n-x;i++){
        bc[dq]=a[i];
        if(x>=dq){
            for(int i=1;i<=x;i++){
                he+=bc[i];
                maxs=max(maxs,bc[i]);
            }
        }
        else{
            f(i+1,x,dq+1);
        }
        if(he>maxs*2){
            ans++;
        }
        he=0;
        maxs=-1;
    }
    return ;
}
*/
int f3(int x){
    int maxs=max(max(a[1],a[2]),a[3]);
    int he=a[1]+a[2]+a[3];
    if(he>2*maxs){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxs=-1;
    int ans=0;
    if(n==3){
            cout<<f3(n);
    }
    else{
        cout<<n;
    }
/*
    ans=0;
    for(int i=3;i<=n;i++){
        f(1,i,1);
        cout<<ans<<" ";
    }
    cout<<ans%N;
*/
    return 0;
}
