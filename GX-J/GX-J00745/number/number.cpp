#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    getline(cin,str);
    vector<int> vec;
    for(int i=0;i<str.size();i++){
        if(str[i]<='9' && str[i]>='0') vec.push_back(str[i]-'0');
    }
    sort(vec.begin(),vec.end());
    for(int i=vec.size()-1;i>=0;i--){
        cout<<vec[i];
    }
}
