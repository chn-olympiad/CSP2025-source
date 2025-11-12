#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,k;
int a[N],b[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int d=0;
    for(int i=0;i<n;i++){
        if(i==0 && a[i]!=k){
            continue;
        }
        if(a[i]==k){
            b[i]=1;
            d=i+1;
        }
       else if(a[i]+(a[i]^a[i-1])==k){
           b[i]=i-d+1;
           d=i+1;
       }
       else{
            a[i]=a[i]+a[i]^a[i-1];
       }
     }
     int ans=0;
       for(int i=0;i<n;i++){
            if(b[i]>ans){
                ans=b[i];
            }
       }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
