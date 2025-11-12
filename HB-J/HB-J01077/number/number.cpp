#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long ans=0;
    cin>>s;
    vector<char> num;
    for(char i:s){
        if(i>='0' && i<='9') num.push_back(i);
    }
    sort(num.begin(),num.end());
    string sans="";
    for(long long i=num.size()-1;i>=0;i--){
        int j=num[i]-'0';
        sans.append(to_string(j));
    }
    ans=stoll(sans);
    cout<<ans<<endl;
    return 0;
}
