#include<bits/stdc++.h>
using namespace std;

bool IsNumber(char number)
{
    if(number >= '0' && number <= '9'){return true;}
    else{return false;}
}
int main ()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s = "";
    char numz[1000001] = {};
    int pl = 0;
    cin >> s;
    for(int i = 0;i <= s.length();i++)
    {
        if(IsNumber(s[i]))
        {
            numz[pl] = s[i];
            pl += 1;
        }
    }
    sort(numz,numz + pl);
    for(int i = pl;i >= 0;i--)
    {
        cout << numz[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
