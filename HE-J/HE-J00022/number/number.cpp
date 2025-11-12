#include<bits/stdc++.h>
using namespace std;
string s;
int barrel[10] = {0};
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    const int l = s.length();
    for(int i = 0;i < l;i++) if(isdigit(s[i])) barrel[s[i] - '0']++;
    for(int i = 1;i <= barrel[9];i++) cout << 9;
    for(int i = 1;i <= barrel[8];i++) cout << 8;
    for(int i = 1;i <= barrel[7];i++) cout << 7;
    for(int i = 1;i <= barrel[6];i++) cout << 6;
    for(int i = 1;i <= barrel[5];i++) cout << 5;
    for(int i = 1;i <= barrel[4];i++) cout << 4;
    for(int i = 1;i <= barrel[3];i++) cout << 3;
    for(int i = 1;i <= barrel[2];i++) cout << 2;
    for(int i = 1;i <= barrel[1];i++) cout << 1;
    for(int i = 1;i <= barrel[0];i++) cout << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
