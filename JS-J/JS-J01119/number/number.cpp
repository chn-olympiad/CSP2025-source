#include <bits/stdc++.h>
using namespace std;
vector<int> v;
string s;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(auto x:s){
        if(x<='9'&&x>='0'){
            v.push_back(x-'0');
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(auto x:v){
        cout<<x;
    }
    return 0;
}
