#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int n,k;
bool cf(){
    for(int i=1;i<=n;i++){
        if(a[i]!=1){
            return false;
        }
    }
    return true;
}
void f(){
    if(k==0){
        cout<<n/2;
    }else if(k==1){
        cout<<n;
    }else{
        cout<<0;
    }
}
bool cff(){
    for(int i=1;i<=n;i++){
        if(a[i]>1){
            return false;
        }
    }
    return true;
}
void ff(){
    if(k==0){
        int num0=0,num1=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                num1++;
            }else{
                num0++;
            }
        }
        cout<<num0+num1/2;
    }else if(k==1){
        int num0=0,num1=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                num1++;
            }else{
                num0++;
            }
        }
        cout<<num1;
    }else{
        cout<<0;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(cf())f();
    else if(cff())ff();
    return 0;
}
