#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,v[10000001],e=1,cnt;
int pd(int l,int r){
    ll as=0;
    for(int i=l;i<=r;i++){
        as=as^v[i];
    }
    return as;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++){
        for(int j=e;j<=i;j++){
            if(pd(j,i)==m){
                cnt++;
                e=i+1;
                break;
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
