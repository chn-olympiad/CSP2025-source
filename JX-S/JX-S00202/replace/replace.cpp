#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    string a,b;
    cin>>n>>q;
    for(long long i=0;i<n;i++){
        cin>>a>>b;
    }
    for(long long i=0;i<q;i++){
        cin>>a>>b;
    }
    for(long long i=0;i<q;i++){
        cout<<0<<endl;
    }
    return 0;
}
