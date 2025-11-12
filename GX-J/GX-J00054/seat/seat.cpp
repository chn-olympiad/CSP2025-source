#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],num,ans;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i)cin>>a[i];
    num=a[1];
    sort(a+1,a+(n*m)+1,greater<int>());
    for(int i=1;i<=n*m;++i){
        if(a[i]==num){
            ans=i;
            break;
        }
    }
    int ansx=1,ansy=1;
    while(--ans){
        if(ansy%2==0){
            --ansx;
            if(ansx<1)++ansy,ansx=1;
        }
        else{
            ++ansx;
            if(ansx>n)++ansy,ansx=n;
        }
    }
    cout<<ansy<<' '<<ansx;
    return 0;
}
