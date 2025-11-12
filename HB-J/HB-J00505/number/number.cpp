#include <bits/stdc++.h>
using namespace std;

vector<int> res;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]<='9'&&s[i]>='0') res.push_back(s[i]-'0');
    }sort(res.begin(),res.end());
    for(int i=res.size()-1;i>=0;i--)cout<<res[i];

    return 0;
}
/*
well,i just want to write something here...
but i cannot type any Chinese words!
why HBers can only use Linux?!!!!??
my english is poor...

now time is 10:57,i have almost 90min and i've finished T1~T3,do you think i can ak?
of course not! now is 11:44 ,T4 i have an idea but no time to write!
*/
