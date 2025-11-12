#include<bits/stdc++.h>
using namespace std;

int j(int n){
    int k=1;
    for(int i=1;i<=n;i++){
            k*=i;
    }
    return k;
}

int A(int n,int m){
    return j(n)/(j(m)*j(n-m));
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string a;
    cin>>a;
    int c[n+78];
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    cout<<A(n,m);
    return 0;
}
