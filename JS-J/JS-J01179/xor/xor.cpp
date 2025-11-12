#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    bool ok=1;
    bool ok1=1;
    int cnt1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            cnt1++;
        }
        if(a[i]!=1){
            ok1=0;
        }
    }
    if(k==1){
        cout<<cnt1<<endl;
        return 0;
    }
    if(ok1==1){
        if(n==1){
            cout<<0<<endl;
            return 0;
        }else {
            cout<<cnt1/2<<endl;
            return 0;
        }

    }


    return 0;
}
