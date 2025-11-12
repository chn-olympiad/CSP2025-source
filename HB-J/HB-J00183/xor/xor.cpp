#include<bits/stdc++.h>
using namespace std;
#define INT long long
INT n,k;
INT a[500010];
INT ans;
bool GetWeight(INT l,INT r){
    INT result=a[l];
    for(INT i=l+1;i<=r;++i){
        result=result^a[i];
    }
    return result==k?true:false;
}
void dfs(INT l,INT r){
    INT templen=1e9,templ,tempr;
    for(INT i=l;i<=r;++i){
        for(INT j=i;j<=r;++j){
            if(GetWeight(i,j)&&j-i+1<templen){
                templen=j-i+1;
                templ=i,tempr=j;
            }
        }
    }
    if(templen!=1e9){
        ++ans;
        if(templ-1>=l) dfs(l,templ-1);
        if(tempr+1<=r) dfs(tempr+1,r);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(INT i=1;i<=n;++i){
        cin>>a[i];
    }
    dfs(1,n);
    cout<<ans;
    return 0;
}
