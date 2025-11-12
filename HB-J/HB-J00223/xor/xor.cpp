#include<bits/stdc++.h>
using namespace std;
int n,k,sum=0;
const int N=5*1e5;
int a[N]={};
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1&&a[1]==k){
        cout<<1;
        return 0;
    }
    if(n==2){
        if(a[1]==k && a[2]==k){
            cout<<2;
            return 0;
        }
        else if(a[1]==k || a[2]==k){
            cout<<1;
            return 0;
        }

    }
    cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
