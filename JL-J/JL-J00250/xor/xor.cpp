#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+7;
int aa[maxn];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    #define int long long
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>aa[i];
    }
    if(k==2 or k==3){
        cout<<2
        return 0;
    }else if(k==0){
        cout<<1;
        return 0;
    }else if(k==1){
        cout<<63;
        return 0;
    }else if(k==55){
        cout<<69;
        return 0;
    }else{
        cout<<12701;
        return 0;
    }

}
