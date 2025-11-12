#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin)
    freopen("number.out","w",stdout)
    int s[1],s[3],s[4];
    cin >> s[1] >> s[3]>>s[4];
    for(int i=1;i<=s;i++)
    {
        if(s[1]<s[3]<s[4])
            cout << s[4] << s[3] << s[1];
        else if(s[4] < s[3] <s[1])
            cout << s[1] << s[3] << s[4];
        else if(s[1] < s[4] <s[3])
            cout << s[3] << s[4] << s[1];
        else if(s[3] < s[4] <s[1])
            cout << s[1] << s[4] << s[3];
        else if(s[4] < s[1] <s[3])
            cout << s[3] << s[1] << s[4];
        else
            cout << s[4] << s[1] << s[3];
    }
    return 0;
}

















}
