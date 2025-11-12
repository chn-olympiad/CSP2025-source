#include <bits/stdc++.h>
using namespace std;
int n,a[5005],z[5005],k,lop,ans;
int MOD=998244353;
bool cheak(int k){
    int maxn=0,summ=0;
    for(int i=1;i<=k;i++){
        if(z[i]==1){
            maxn=max(maxn,a[i]);
            summ+=a[i];
        }
    }
    if(summ>maxn*2){
            //cout<<"T"<<summ<<" "<<maxn<<endl;
        return true;
    }else{
        return false;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int x=1;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        x*=2;
    }

    for(int i=1;i<=x;i++){
        z[1]++;
        k=0;
        lop=0;
        while(1){
            k++;
            if(z[k]==1){
                lop++;
            }
            if(z[k]>1){
                z[k]=0;
                z[k+1]++;
            }
            if(k>i){
                break;
            }
        }
        if(lop>=3){
            if(cheak(k)){

                ans++;
                ans=ans%MOD;
            }
        }
    }
    cout<<ans%MOD<<endl;
    return 0;
}
