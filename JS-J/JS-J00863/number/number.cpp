#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e6 + 10;
int cnt;
int res[N];
int num[N];
string s;

bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            cnt++;
            num[cnt] = s[i] - '0';
        }
    }

    sort(num + 1,num + cnt + 1,cmp);
    for(int i = 1;i <= cnt;i++)
    {
        cout << num[i];
    }
    cout <<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
