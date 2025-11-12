#include<bits/stdc++.h>
using namespace std;
const int N=500;
int a[N];
int c[N];
int n,m;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    int ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*i;
    }
    ans=ans%998;
    ans=ans%244;
    ans=ans%353;
    cout<<ans;
}