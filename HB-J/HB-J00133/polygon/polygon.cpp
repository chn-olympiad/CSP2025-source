#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in",r,stdin);
    freopen("polygon.out",w,stdout);
    int a,ans=0,tmdccf;
    cin>>a;
    int arr[a];
    for(int i=0;i<a;i++)cin>>arr[i];
    for(int i=0;i<a;i++)ans+=i;
    cout<<ans-3;
    return 0;
}
