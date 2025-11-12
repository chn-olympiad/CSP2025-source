#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    if(k){
        int b,s=0;
        for(int i=1;i<=n;i++){
            cin>>b;
            if(b>0){
                s++;
            }
        }
        cout<<s;
    }
    else{
        int b,s=0,d=0;
        for(int i=1;i<=n;i++){
            cin>>b;
            if(b==0){
                s++;
                s+=d/2;
                d=0;
            }
            else{
                d++;
            }
        }
        cout<<s;
    }
    return 0;
}
//0
//0 1 1 1 1 0 0 1 1
