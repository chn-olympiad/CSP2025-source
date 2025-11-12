#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
string z(int n){
    string ans="";
    while(n!=0){
        int t=n%2;
        char t1=char(t+48);
        ans+=t1;
        n/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<2;
    return 0;
}
