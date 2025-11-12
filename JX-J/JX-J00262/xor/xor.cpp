#include<bits/stdc++.h>
using namespace std;
long long a[100000],b,k,n,x,y,z;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            x++;
        }
        if(a[i]==1){
            y++;
        }if(a[i]==k)z++;
    }if(y==n&&k==0)cout<<0;
    else if(k==1)cout<<y;
    else if(k==0&&x+y==n)cout<<n-y;
    else cout<<z;
    return 0;
}


