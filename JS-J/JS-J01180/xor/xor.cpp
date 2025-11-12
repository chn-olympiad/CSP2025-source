#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n, k, a[maxn];
bool check(){
    for(int i=0; i<n; i++){
        if(a[i]!=1){
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("xor.in", "r", stdin);
    froopen("xor.out". "w", stdout);
    cin>>n>>k;
    for(int i=0; i<n;  i++){
        cin>>a[i];
    }
    if(k==0&&check()){
        if(n<2){
            cout<<0;
            return 0;
        }
        else if(n==2){
            cout<<1;
            return 0;
        }
        else{
            cout<<n/2;
            return 0;
        }
    }

    return 0;
}
