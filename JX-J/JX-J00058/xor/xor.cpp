#include<iostream>
using namespace std;
int l[500010],n,k,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    int r1=0,r0=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&l[i]);
        if(l[i]==1)r1++;
        else if(l[i]==0) r0++;
    }
    if(r1==n){
        cout<<n%2+1;//10pts
    }
    else{
       if(k){
            if(r0==n) cout<<0;
       }
       else{
            if(r1==n) cout<<0;
       }
    }
    return 0;
}
