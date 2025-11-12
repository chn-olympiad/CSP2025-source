#include <bits/stdc++.h>
using namespace std;
vector<char> b;
bool cmp(int _1,int _2){
    return _1 > _2;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=0;i<a.length();i++){
        if(a[i]>='0'&&a[i]<='9'){
            b.push_back(a[i]);
        }
    }
    sort(b.begin(),b.end(),cmp);
    bool zero=true;
    if(b[0]=='0'){
        cout<<0;
        return 0;
    }
    for(int i=0;i<b.size();i++){
        printf("%c",b[i]);
    }
    return 0;
}
