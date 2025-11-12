#include<bits/stdc++.h>
using namespace std;

int a[500005];
int n, k;

int get_xor(int l, int r){
    int result = a[l];
    for(int i=l+1; i<=r; i++){
        result = result^a[i];
    }
    return result;
}


int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];
    int c = 0;
    int l = 1, r = 1;
    for(int i=1; i<=n; i++){
        if(get_xor(l, r) == k){
            c++;
            r++;
            l = r;
        }else{
            r++;
        }
    }
    cout<<c;
    return 0;
}
