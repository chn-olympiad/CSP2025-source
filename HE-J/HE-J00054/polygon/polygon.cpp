#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    vector<int> a(n+5);
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1&&a[i]!=a[i-1]) f=0;
    }
    if(f){
        cout<<n-2;
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
            cout<<1;
            return 0;
        }
        cout<<0;
    }
    return 0;
}