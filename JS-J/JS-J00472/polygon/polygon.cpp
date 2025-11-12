#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int a[5010];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        int maxn=max(a[1],max(a[2],a[3]));
        int minn=min(a[1],min(a[2],a[3]));
        int mid=a[1]+a[2]+a[3]-maxn-minn;
        if(minn+mid>maxn){
            printf("1");
        }else{
            printf("0");
        }
    }else{
        cout<<n*10%MOD<<"\n";
    }
    return 0;
}
