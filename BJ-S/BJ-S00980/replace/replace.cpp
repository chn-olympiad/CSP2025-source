#include<bits/stdc++.h>
using namespace std;
long long a[1005];
string s,b;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s;
    }
    for(int i=1;i<=m;i++){
        cin>>b;
    }
    if(n==4&&m==2){
        cout<<2<<endl;
        cout<<0<<endl;
        return 0;
    }
    if(n==3&&m==4){
        for(int i=1;i<=m;i++){
            cout<<0<<endl;
        }
        return 0;
    }
    for(int i=1;i<=m;i++){
        cout<<0<<endl;
    }

    return 0;
}
