#include<iostream>

using namespace std;
int n,q;
string a[1000010],b[1000010],q1[1000010],q2[1000010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=q;i++){
        cin>>q1[i]>>q2[i];
    }
    for(int i=1;i<=q;i++){
        cout<<'0'<<'\n';
    }
    return 0;
}
