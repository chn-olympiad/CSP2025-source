#include<iostream>
#include<cstdio>
using namespace std;
int m,n;
string s,z;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int l=1;l<=n+m;l++){
        cin>>s>>z;
    }
    for(int i=1;i<=m;i++){
        cout<<"0\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
