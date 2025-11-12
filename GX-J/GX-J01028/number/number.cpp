#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::string;
using std::vector;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string x;
    vector<int> n;
    cin>>x;
    for(int i:x){
        if(i>=48&&i<=57){
            n.push_back(i-48);
        }
    }
    sort(n.begin(),n.end(),std::greater<int>());
    for(int i:n){
        cout<<i;
    }
    return 0;
}
