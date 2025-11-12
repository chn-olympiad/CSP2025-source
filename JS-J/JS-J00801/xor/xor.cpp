#include<bits/stdc++.h>
using namespace std;
int n,k,s=-1,y;
int qz[500100];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>qz[i];
    }
    for(int i=n-1;i>=0;i--){
        if(s==k){
            y++;
            s=-1;
        }
        if(s==-1){
            s=qz[i];
            continue;
        }
        s^=qz[i];
    }if(s==k){
        y++;
    }cout<<y;
    return 0;
}
