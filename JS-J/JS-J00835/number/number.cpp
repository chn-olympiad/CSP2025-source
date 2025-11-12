#include <bits/stdc++.h>

using namespace std;
long long t[11];
int main()
{
    string s;
    cin>>s;
    freopen("number","r",stdin);
    freopen("number","w",stdout);
    for(long long i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            t[s[i]-'0']++;
        }
    }
    for(long long i=9;i>=0;i--){
        for(int j=1;j<=t[i];j++){
            cout<<i;
        }
    }
    return 0;
}
