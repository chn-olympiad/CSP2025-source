#include <bits/stdc++.h>
using namespace std;
int c[505];
int main(){
    freopen("employ4.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,a=0;
    string s;
    cin>>n,m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        if(s[i-1]){
            a++;
        }
    }
    long long b=n;
    for(int i=1;i<=a;i++){
        b+=b*n;
        b=b%998244353;
    }
    cout<<b<<endl;
    return 0;
}