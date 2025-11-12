#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
    preopen("polygon.in","r",stdin);
    preopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin<<a[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=a[i];
    }
    cout<<ans;
    return 0;
}
