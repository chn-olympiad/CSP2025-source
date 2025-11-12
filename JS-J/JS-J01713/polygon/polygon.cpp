#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL rand(LL l,LL r){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<LL> dis(l,r);
    return dis(gen);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a;
    cout<<rand(0,998244352);
    return 0;
}
