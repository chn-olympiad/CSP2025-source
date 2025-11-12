#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL n, a[5005], num;
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(j-i>=3){
                LL maxij=-1, ans=0;
                for(int z=i;z<=j;z++){
                    maxij=max(maxij, a[z]);
                    ans+=a[z];
                }
                if(ans>2*maxij) {num++;}
                if(num==998244353) num%=998244353;
            }
        }
    }
    cout<<num;
    return 0;
}
