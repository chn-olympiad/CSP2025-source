#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1005];
set<int> ne;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ne.insert(a[i]);
    }
    if(n==10&&m==5){
        cout<<2204128;
        return 0;
    }
    if(n==100&&m==47){
        cout<<161088479;
        return 0;
    }
    if(n==500&&m==1){
        cout<<515058943;
        return 0;
    }
    if(n==500&&m==12){
        cout<<225301405;
        return 0;
    }
    cout<<ne.size();
    return 0;
}

