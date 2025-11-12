#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int len = s.size(),cnt = 0;
    char num[len+1];
    for(int i = 0;i < len;i++)
    {
        if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
        {
            num[cnt] = s[i];
            cnt++;
        }
    }
    sort(num,num+cnt);
    for(int i = cnt-1;i >= 0;i--)
    {
        cout << num[i];
    }
    cout << endl;
    return 0;
}
