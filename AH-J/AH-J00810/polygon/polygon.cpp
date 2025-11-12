#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n<3)cout<<0;
    else{
        int s=0,ans=0;
        for(int i=0;i<n;i++){
            s+=a[i];
            ans=max(a[i],ans);
        }
        if(s>ans*2)cout<<1;
        else cout<<0;
    }
    return 0;
}
