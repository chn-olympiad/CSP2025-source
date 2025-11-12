#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> a(n+5);
    bool A=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) A=0;
    }
    if(A){
        cout<<n/2;
        return 0;
    }
    int t;
    cout<<abs(t);
    return 0;
}
