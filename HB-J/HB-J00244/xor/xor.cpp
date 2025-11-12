#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,m,a=0;
    cin>>n>>m;
    int s[n+5];
    for(int i=0;i<n;i++){
        cin>>s[i];
        if(s[i]==m){
            a++;
        }
    }
    cout<<a;
    return 0;
}
