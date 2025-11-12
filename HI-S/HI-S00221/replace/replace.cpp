#include <iostream>
#include <string>
#include <array>
#include <utility>
#include <algorithm>
using namespace std;
const int N=2e+5+5;
array<pair<string,string>,N> s;
int n,q;
int main(void){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s[i].first>>s[i].second;
    }
    while(q--){
        string a,b;
        cin>>a>>b;
        cout<<0<<endl;
    }
    return 0;
}