#include<bits/stdc++.h>
using namespace std;
int buk[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string n;
    cin >> n;
    for(char i : n)
    {
        if(i >= '0' and i <= '9')
        {
            buk[i - '0']++;
        }
    }
    for(int i = 9;i >= 0;i--)
    {
        while(buk[i]--)
        {
            cout << i;
        }
    }
	return 0;
}
