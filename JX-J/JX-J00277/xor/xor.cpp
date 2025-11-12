#include<bits/stdc++.h>
using namespace std;
int cnt,n,k,a[500010],x,s,e;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        x=a[i];
        if(a[i]==k){
            cnt++;
            s=i,e=i;
            continue;
        }
        for(int j=i+1;j<=n;j++){
            x^=a[j];
            if(x==k){
//                cout<<i<<" "<<j<<"\n";
                s=i,e=j;
                cnt++;
                break;
            }
        }
        i=e;
    }
    cout<<cnt;
}
