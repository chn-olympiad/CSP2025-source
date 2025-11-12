#include<iostream>
#include<algorithm>
using namespace std;
string s,s2;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            s2+=s[i];
        }
    }
    sort(s2.begin(),s2.end(),greater<int>());
    cout<<s2;
    return 0;
}
