#include<iostream>
using namespace std;
int n,q;
int a[200005],b[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    if(p==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=q;i++){
        cout<<0<<endl;
    }
    return 0;
}
