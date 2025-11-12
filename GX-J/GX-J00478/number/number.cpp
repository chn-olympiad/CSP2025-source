#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    if(s.size()<=1 && ("0"<=s && s<="9"))
    {

        cout << s;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
