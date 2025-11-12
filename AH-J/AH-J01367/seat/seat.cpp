#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
int n,m;
int a[maxn*maxn];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i){
        cin>>a[i];
    }
    int num=1;
    for(int i=2;i<=n*m;++i){
        if(a[i]>a[1]){
            ++num;
        }
    }
    int ans=((num-1)/n+1);
    //cout<<num<<' '<<ans<<endl;
    if(ans%2==1){
        cout<<ans<<' '<<((num-1)%n+1)<<endl;
    }
    else{
        cout<<ans<<' '<<(n-num%n+1)<<endl;
    }
    return 0;
}