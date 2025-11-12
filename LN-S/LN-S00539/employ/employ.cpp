#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,n;
    long long f=1;
    cin>>a>>b;
    string s;
    cin>>s;
    for(int i=0;i<a;i++){
            cin>>n;
            f*=(n==0?1:n);
    }
    cout<<f;
}
