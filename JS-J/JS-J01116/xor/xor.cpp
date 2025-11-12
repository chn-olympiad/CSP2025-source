#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[50001],b=0,c=1,d;
    cin>>n>>k;
    int l[n],r;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
        for(int i=c;i<=n;i++){
            a[i]=a[i]|a[i+1];
            d=a[i]&a[i+1];
            a[i]-=d;
            if(a[i]==k){
                b++;
                c=i;
                break;
            }
        }
    }
    if(n==1)
        cout<<"0";
    else
        cout<<"1";
    return 0;
}
