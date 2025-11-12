#include<bits/stdc++.h>
using namespace std;
string s;
int mp[10];
int main()
{
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    cin >> s;
    for(int i = 0 ; i < s.size() ; i ++)
    {
        if('0' <= s[i] && s[i] <= '9') mp[s[i] - '0'] ++;
    }
    if(mp[1] == 0 && mp[2] == 0 && mp[3] == 0 && mp[4] == 0 && mp[5] == 0 && mp[6] == 0 && mp[7] == 0 && mp[8] == 0 && mp[9] == 0) printf("0\n");
    else
    {
        for(int i = 9 ; i >= 0 ; i --)
        {
            for(int j = 1 ; j <= mp[i] ; j ++) printf("%d" , i);
        }
    } 
    return 0;
}

// wo AK le!!!!
// guanzhu luogu uid 719978 DYYqwq xie xie miao qwq.