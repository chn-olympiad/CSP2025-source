#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("replace.in","w",stdout);
    int n=1000,q=1000;
    cout<<n<<' '<<q<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) cout<<'a'; cout<<' ';
        for(int j=1;j<i;j++) cout<<'a'; cout<<"b\n";
    }
    for(int i=1;i<=q;i++){
        for(int j=1;j<=n;j++) cout<<'a'; cout<<' ';
        for(int j=1;j<n/2;j++) cout<<'a'; cout<<"b";
        for(int j=1;j<=n/2;j++) cout<<'a'; cout<<"\n";
    }
}