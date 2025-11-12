#include<iostream>
using namespace std;
float s[1000],t[1000];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=q;i++){
        for(int j=1;j<=n;j++){
            cin>>s[j];
        }
    for(int i=1;i<=q;i++){
        cin>>t[i];
    }
    return 0;
}
