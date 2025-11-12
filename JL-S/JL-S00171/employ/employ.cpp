#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long k=1;
    int m;
    string s;
    freopen("empoly.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        int a;
        k *= (a+1);
        k %= 998244353;
        cin>>a;
    }
    cout<<min(pow(n-m,m-1),k);
}
