#include<bits/bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freoprn("xor.out","w",stdout);
    int n,k;
    int cnt=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=k;i++){
        if(a[i]==a[i+1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
