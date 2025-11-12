#include<bits/stdc++.h>
using namespace std;
int a[600000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int cnt=0;
    for(int i=0;i<n;i++){
       cin>>a[i];
       if(a[i]==k){
           cnt++;
       }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int l=i,r=j;
            while(l<r){
                int l1=l,l2=l+1;
                if(l1!=l2){
                   cnt++;
                }
                l++;
            }
        }
    }
    return 0;
}
