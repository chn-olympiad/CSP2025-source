#include <bits/stdc++.h>
using namespace std;
vector<char> vec;
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    for(char c : str){
        if(c<='9' && c>='0'){
            vec.push_back(c);
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i];
    }
    return 0;
}
