#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[100000],t=0,s=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>t){
           t=a[i];
        }
        s=s+=a[i];
    }
    cout<<s;
    return 0;
}
