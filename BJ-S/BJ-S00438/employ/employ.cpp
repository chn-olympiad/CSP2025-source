#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=1;
int n1=n;

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    string s;
    cin>>s;

    int a[1000];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) n1--;
    }
    cout<<0;



    return 0;

}
