#include <bits/stdc++.h>
using namespace std;
int a[500040],n,k,sum=0;
bool b[500040];
bool work(int l,int r){
    int j=a[l];
    for(int i=l+1;i<=r;i++){
        j=j^a[i];

    }
    if(j==k){
        return true;
    }
    return false;
}
void aaaw(int l,int r){
    for(int i=l;i<=r;i++){
        b[i]=1;
    }
}
bool pan(int l,int r){
    for(int i=l;i<=r;i++){
        if(b[i]){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            if(pan(j,j+i)){
                continue;
            }
            if(work(j,j+i)){
                aaaw(j,j+i);

                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
