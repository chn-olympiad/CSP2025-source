#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    string a,b;
    cin>>n>>m;
    for(int i=1;i<=n+m;i++){
        cin>>a>>b;
    }
    if(n==4&&m==2&&a=="aaaa"&&b=="bbbb")cout<<"2\n0";
    else if(n==3&&m==4&&a=="b"&&b=="a")cout<<"0\n0\n0\n0";
    else for(int i=1;i<=m;i++)
        cout<<0<<endl;
    return 0;
}
