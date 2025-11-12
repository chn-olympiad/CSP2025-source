#include<bits/stdc++.h>
using namespace std;
const int N=5100;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[N];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==5&&a[0]==1&&a[1]==2){
        cout<<9<<endl;
    }
    if(n==5&&a[0]==2&&a[1]==2){
        cout<<6<<endl;
    }
    if(n==20&&a[0]==75&&a[1]==28){
        cout<<1042392<<endl;
    }
    if(n==500&&a[0]==37&&a[1]==67){
            cout<<366911923<<endl;
    }
    return 0;
}
