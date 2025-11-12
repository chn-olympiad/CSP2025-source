#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string x;
string res;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> x;
    for(auto i:x)   if(i>='0'&&i<='9')  res.push_back(i);
    sort(res.begin(),res.end(),[](char a,char b){return a>b;});
    cout << res;
    return 0;
}
