#include<bits/stdc++.h>
using namespace std;
int n,k,as;
int a[500010];
int ki(int l,int r){
    int h=0;
    for(int i=l;i<=r;i++){
        h=h^a[i];
    }
    return h;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(ki(i,j)==k){
                as++;
                i=j;
                break;
            }
        }
    }
    cout<<as;
    return 0;
}
