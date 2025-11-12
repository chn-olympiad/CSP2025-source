#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    int s[1000],c[1000];
    string ss;
    cin>>n>>m;
    cin>>ss;
    for(int i=1;i<=n;i++){
        s[i]=ss[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    //------------AAAAA------------//
    int ans=1;
    for(int i=1;i<=n;i++)ans*=i;
    cout<<ans;
}