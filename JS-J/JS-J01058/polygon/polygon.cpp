#include <bits/stdc++.h>
using namespace std;
const int mmod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n=3){
        int mmax=0;
        for(int i=0;i<n;i++){
            mmax=max(mmax,a[i]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt=cnt+a[i];
        }
        if(cnt>2*mmax){
            cout<<1<<endl;
            return 0;
        }
    }else{
        cout<<0;
    }
    return 0;
}
