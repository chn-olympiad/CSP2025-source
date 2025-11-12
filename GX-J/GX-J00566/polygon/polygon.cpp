#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,l=0,s=0,m=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            m=max(a[j],m);
            s+=a[j];
            if(s>m*2){
                l++;
            }
        }
        s=0;
        m=0;
    }
    cout<<l%998%244%353;
    return 0;
}
