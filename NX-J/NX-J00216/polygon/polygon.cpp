#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
long long n,a[N],mx=0,cnt=0,c=0,l,r;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    l=1;
    r=2;
    while(1){
        if(l>n) break;
        if(r>n){
            l++;
            r=l+1;
        }
        for(i=l;i<=r;i++){
            cnt+=a[i];
            mx=max(mx,a[i]);
        }
        if(cnt>(mx*2)){
           c++;
        }
        r++;
    }
    cout<<c;
    return 0;
}
