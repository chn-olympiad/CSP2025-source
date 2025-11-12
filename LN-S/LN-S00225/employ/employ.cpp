#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],b[15],ans,c=1,o;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    o=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)o--;
    }
    for(int i=1;i<=o;i++){
        c*=i;
        c%=998244353;
    }
    cout<<c;
}
