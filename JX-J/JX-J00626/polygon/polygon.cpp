#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","W",stdout);
    int n,a[10000];
    long long int x=0;
    cin>>n;
    int max=a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(a[i]>max) max=a[i];
    }
    if(max==1){
        for(int i=3;i<n;i++){
                int c=1,s=1;
            for(int j=n;j>=i;j--){
                c*=j;
            }for(int j=i;j>=1;j--){
                s*=j;
            }
            x+=(c/s);
        }
        cout<<x%998244353;
    }
    return 0;
}
