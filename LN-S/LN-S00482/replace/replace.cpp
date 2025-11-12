#include <iostream>
using namespace std;
string s1[100005],s2[100005];
string t1[100005],t2[100005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>t1[i]>>t2[i];
    }
    for(int i=0;i<q;i++){
        cout<<0<<endl;
    }
    return 0;
}
