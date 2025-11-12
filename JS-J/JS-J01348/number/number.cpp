#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    multiset < int > si;
    for(int i = 0;i < s.size();i ++)
    {
        if(s[i] >= '0' && s[i] <= '9'){
            si.insert(s[i]-'0');
        }
    }
    for(multiset < int > :: reverse_iterator it = si.rbegin();it != si.rend();it ++){
        printf("%d",*it);
    }
    return 0;
}
