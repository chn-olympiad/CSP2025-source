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
    int c0=0,c1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            c1++;
        }
        if(a[i]==0){
            c0++;
        }
    }
    if(k==1){
        cout<<c1;
    }else if(k==0){
        int c=0;
        for(int i=1;i<n;i++){
            if(a[i]==1&&a[i+1]==1){
                c++;
                i+=2;
            }
        }
        cout<<c+c0;
    }
    return 0;
}
