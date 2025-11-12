#include<bits/stdc++.h>
using namespace std;
int n,_0,_1,k;
int a[500005];
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            _1++;
        }else{
            _0++;
        }
    }
    if(k==1){
        cout<<_1<<endl;
    }else{
        cout<<_0+_1/2<<endl;
    }
    return 0;
}
