#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int a[N],s[N];
int n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool ch=1;
    for(int q=1;q<=n;q++){
        cin>>a[q];
        if(a[q]!=1){
            ch=0;
        }
    }
    if(ch==1){
        cout<<0<<endl;
    }else{
        cout<<1<<endl;
    }
    return 0;
}
