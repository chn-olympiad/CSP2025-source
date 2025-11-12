#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int qzy[500005];
int cnt,h,t;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        qzy[i]=a[i]^qzy[i-1];
    }
    h=1;
    for(int i=1;i<=n;i++){
        for(int j=h;j<=i;j++){
            int p=qzy[i]^qzy[j-1];
            if(p==k){
                h=i+1;
                cnt++;
                break;
            }
        }
    }
    cout<<cnt;
}