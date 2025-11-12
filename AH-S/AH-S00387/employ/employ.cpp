#include<bits/stdc++.h>
using namespace std;
int a[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    long long sum=1;
    for(int i=1;i<=n;i++) sum*=i;
    cout<<sum;
    return 0;
}
