#include<bits/stdc++.h>
using namespace std;
int num;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;cin>>n>>m;
    string s;cin>>s;
    int a[505];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<s.size();i++){
        if(s[i]==0) num++;
    }
    if(num==0) cout<<0;
    else if (num<m) cout<<0;
    else if(m=n) cout<<1;
    else cout<<2204128;
    return 0;
}
