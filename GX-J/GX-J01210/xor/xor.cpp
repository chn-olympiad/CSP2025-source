#include<bits/stdc++.h>
using namespace std;

long long n,k,a[500010],ans=0,ansn=0,ansm=0,chang=0,maxchang=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0||n<=2){
        cout<<'1';
        return 0;
    }
    for(int i=1;i<=n;i++){
        ansn=a[i];
        chang=0;
        for(int j=i+1;j<=n;j++){
            ansn=ansn|a[j];
            if(ansn==k){
                maxchang=max(maxchang,chang);
                break;
            }
            chang++;
        }
    }
    cout<<maxchang;

    return 0;
}