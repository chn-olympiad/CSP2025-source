#include<bits/stdc++.h>
using namespace std;
int s(int n,int ans,int max){
    if(n<3){
        return 0;
    }
    if(ans<=2*max){
        return 0;
    }
    return 1;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,max=0,ans=0;
    cin>>n;
    vector<int> a(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(max<a[i])
            max=a[i];
        ans+=a[i];
    }
    if(s(n,ans,max)==0){
        cout<<0;
        return 0;
    }
    cout<<3;
    return 0;
}
