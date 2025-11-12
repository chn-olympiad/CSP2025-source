#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,k;
int a[N],b[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    if(b[n-1]==1){
        if(b[0]==1){
            cout<<n/2;
        }
        else{
            if(k==0){
                cout<<n/2+(upper_bound(b,b+n,0)-b)*0.5;
            }
            else{
                cout<<n/2+(n-2*(upper_bound(b,b+n,0)-b))*0.5;
            }
        }
    }
    return 0;
}
