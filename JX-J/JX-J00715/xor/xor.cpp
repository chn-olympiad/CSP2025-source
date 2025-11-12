#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r=1;
    while(1){
        if(l==n&&r==n){
            cout<<s;
            return 0;
        }
        int p=1;
        for(int i=l,i<=r;i++){
            p^=a[i];
        }
        if(p<k){
            r++;
        }else{
            l=r+1;
            s++;
        }
    }
}
