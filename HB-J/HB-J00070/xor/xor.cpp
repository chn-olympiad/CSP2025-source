#include<bits/stdc++.h>
using namespace std;
int c[100001],n,ans; //score:5
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>c[i];
    }
    if(n==2){
        if(c[0]==0&&c[1]==0){
            cout<<2<<endl;
            return 0;
        }
        if(c[0]==c[1]||c[0]==0||c[1]==0){
            cout<<1<<endl;
            return 0;
        }
        cout<<0<<endl;
    }
    if(n==1){
        if(c[0]==0) cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
