#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=q;i++){
        if(i%3==0) cout<<n/2<<endl;
        else cout<<n/2-1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}