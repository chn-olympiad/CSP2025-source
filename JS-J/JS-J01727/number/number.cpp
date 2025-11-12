#include<bits/stdc++.h>
using namespace std;
int b[10];
char a;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string c;
    cin >> c;
    for(int i = 0;i < c.size();i++)
    {
        a = c[i];
        if(int(a) > 47 && int(a) < 58)
        {
            b[int(a) - 48]++;
        }
    }
    for(int i = 9;i >= 0;i--)
    {
        for(int j = 1;j <= b[i];j++)
        {
            cout << i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
