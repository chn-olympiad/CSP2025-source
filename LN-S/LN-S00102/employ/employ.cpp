#include<bits/stdc++.h>
using namespace std;
int n,m,x=1;
string s;
int a[501];
int b[501];
long long ans;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0){
            b[x]=a[i];
            x++;
        }
    }
    ans=b[1];
    for(int i=2;i<=x;i++){
        ans=b[i]*ans%988244353;
    }
    cout<<ans;
    return 0;
}
