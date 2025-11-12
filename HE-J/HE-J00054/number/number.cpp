#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    sort(s.begin(),s.end(),greater<char>());
    int pos=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            pos=i;
            break;
        }
    }
    cout<<s.substr(pos);
    return 0;
}
