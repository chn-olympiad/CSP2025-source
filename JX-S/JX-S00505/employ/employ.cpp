#include<bits/stdc++.h>
using namespace std;
int const N=1e5;
int a[N];
long long d;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d*=a[i];
    }
    cout<<d;
}

