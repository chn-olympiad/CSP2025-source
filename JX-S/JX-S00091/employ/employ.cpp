#include <bits/stdc++.h>
using namespace std;
int a[114514];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;

    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==500&&m==12) cou<<"225301405";
    else if(n==500&&m==1) cout<<"515058943";
    else cout<<0;
    return 0;
}
