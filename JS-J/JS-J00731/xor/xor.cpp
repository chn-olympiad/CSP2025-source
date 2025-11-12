#include<bits/stdc++.h>
using namespace std;
int n,k,a[100001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]^=a[i-1];
    }
    int l=0,r=1,sum=0;
    while(l<r&&r<=n){
        if(a[l] ^ a[r] == k){
            sum++;
            r++;
        }
        if(a[l] ^ a[r] < k){
            r++;
        }
        if(a[l] ^ a[r] > k){
            l++;
        }
    }
    cout<<sum<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
