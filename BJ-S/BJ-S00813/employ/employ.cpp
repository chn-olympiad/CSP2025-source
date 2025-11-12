#include<bits/stdc++.h>
using namespace std;

int n,m,a[505],k,jia,num=0;
string s;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m>s.size()){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=m;i++){
        num=(num*i)%998244353;
    }
    cout<<num;

















    return 0;
}


