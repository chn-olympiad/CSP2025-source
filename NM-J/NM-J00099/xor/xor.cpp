#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=2e6+7;
int a[N];
int c0,c1,c2,c3,c4,c5,c6,c7,c8,c9;
string s;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0){
            c0++;
        }
        if(a[i]==1){
            c1++;
        }
        if(a[i]==2){
            c2++;
        }
        if(a[i]==3){
            c3++;
        }
        if(a[i]==4){
            c4++;
        }
        if(a[i]==5){
            c5++;
        }
        if(a[i]==6){
            c6++;
        }
        if(a[i]==7){
            c7++;
        }
        if(a[i]==8){
            c8++;
        }
        if(a[i]==9){
            c9++;
        }
    }
    if(k==0){
        if(c0!=0){
            cout<<c0;
        }
        else{
            cout<<1;
        }
        return 0;
    }
    if(k==1){
        cout<<c1;
        return 0;
    }
    return 0;
}
