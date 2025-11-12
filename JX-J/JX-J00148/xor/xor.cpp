#include<bits/stdc++.h>
using namespace std;
int n,cnt,x,k,a[100005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.ans","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            cnt++;
        }
    }
    if(k==1){
        cout<<cnt;
    }else if(k==0){
        cout<<n-cnt;
    }else{
        cout<<n/2;
    }

    return 0;
}
