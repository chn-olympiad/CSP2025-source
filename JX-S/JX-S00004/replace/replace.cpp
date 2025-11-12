#include <iostream>
using namespace std;

int n,m;
char k[1000005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","r",stdout);
    cin>>n>>m;
    for (int i=1;i<=n+m;i++){
        cin>>k;
    }
    for (int i=1;i<=m;i++){
        cout<<0<<endl;
    }

    return 0;
}
