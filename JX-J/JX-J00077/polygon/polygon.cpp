#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],ans;
int main(){
    freopen("polygon.in","w","stdin")
    freopen("polygon.out","r","stdout")
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(n==3&&a[i]+a[i+1]<a[i+2]) {cout<<0;fclose("stdin") fclose("stdout") }
        else if(n==3&&a[i]+a[i+2]<a[i+1]) {cout<<0;fclose("stdin") fclose("stdout") }
        else if(n==3&&a[i+1]+a[i+2]<a[i]) {cout<<0;fclose("stdin") fclose("stdout") }
    }
    cout<<1;
    fclose("stdin")
    fclose("stdout")
    return 0;
}
