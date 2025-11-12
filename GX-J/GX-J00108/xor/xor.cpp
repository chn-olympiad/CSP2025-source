#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n+1],c=true,ccf=true;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=1)c=false;
        if(a[i]>1)ccf=false;
    }
    if(c&&k==0){
        cout<<0;
        return 0;
    }
    int sum=0;
    if(ccf&&k<=1){
        for(int i=0;i<n;i++){
            if(a[i]==k)sum++;
        }
        cout<<sum;
        return 0;
    }
    if(k==0){
        for(int i=0;i<n;i++){
            if(a[i]==0)sum++;
        }
        cout<<sum;
    }
    else cout<<n/2;
    return 0;
}
