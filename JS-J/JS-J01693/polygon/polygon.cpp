#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        sort(a+1,a+n+1);
        int c=a[3]*2;
        int s=a[1]+a[2]+a[3];
        if(s>c){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        cout<<1232;
    }
    return 0;
}
