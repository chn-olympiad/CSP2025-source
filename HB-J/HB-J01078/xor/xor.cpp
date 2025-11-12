#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int cnt;
        for(int j=i;j<=n;j++){
            if(j==i){
                cnt=a[i];
            }
            if(cnt==k){

            }
        }
    }
    return 0;
}
