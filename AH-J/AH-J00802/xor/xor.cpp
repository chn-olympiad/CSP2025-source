#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
long long a[N],k,n,cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==a[i+1]){
                cnt++;
                i++;
            }
        }
        cout<<cnt;
    }
    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i+1]){
                cnt++;
                i++;
            }
        }
        cout<<cnt;
    }
    return 0;
}
