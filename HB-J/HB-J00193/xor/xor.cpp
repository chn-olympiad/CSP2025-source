#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],temp,cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    if(k==1){
        for(int i=0;i<n;i++){
            if(a[i]==1) cnt++;
        }
    }
    else if(k==0){
        for(int i=0;i<n;i++){
            if(a[i]==0) cnt++;
            if(a[i]==1&&a[i+1]==1) cnt++,i++;
        }
    }
    else{
        for(int i=0;i<n;i++){
            temp^=a[i];
            if(temp==k) cnt++,temp=0;
        }
    }
    cout<<cnt;
    return 0;
}
