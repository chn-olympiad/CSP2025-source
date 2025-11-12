#include <bits/stdc++.h>
// #include <dragonpro.h>
// #define ll long long
// #define pr pair<,>
using namespace std;
int num[15];
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s; cin >> s;
    memset(num , 0 , sizeof(num));
    for(int i = 0 ; i < s.size() ; i ++)
    {
        int c = int(s[i] - '0');
        if(c >= 0 && c <= 9) num[c] ++;
    }
    for(int i = 9 ; i >= 0 ; i --)
        for(int j = 1 ; j <= num[i] ; j ++)
            cout << i;
    cout << endl;
	return 0;
}
// dragonpro-presents