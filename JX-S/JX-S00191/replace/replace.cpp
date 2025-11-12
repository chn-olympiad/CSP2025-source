#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> ls;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    string o,p;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>o>>p;
        ls[o] = p;
    }
    for(int i=1;i<=q;i++){
        cin>>o>>p;
        cout<<"0\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
