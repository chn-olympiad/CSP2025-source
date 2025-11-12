#include<bits/stdc++.h>
#define int long long
using namespace std;
using str=string;
using ldou=long double;
signed main(){
    #ifndef NOFREOPEN
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    #endif // NOFREOPEN
    str s;
    cin>>s;
    vector<int> num;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num.push_back(s[i]-'0');
        }
    }
    sort(num.begin(),num.end());
    for(int i=num.size()-1;i+1;i--){
        cout<<num[i];
    }
    return 0;
}
