#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(char c:s){
        if(isdigit(c))a.push_back((int)(c-'0'));
    }
    sort(a.begin(),a.end(),[](int x,int y){return x>y;});
    for(auto n:a){
        cout<<n;
    }
    return 0;
}
