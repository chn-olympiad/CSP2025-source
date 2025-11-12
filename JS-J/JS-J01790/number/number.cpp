#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6+5;
int a[MAXN];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n = s.size();
    bool flag = 0;
    int cur = 0;
    for (int i=0;i<n;i++)
    {
        if ((flag == 1 && s[i] == '0') || (s[i] >= '1' && s[i] <= '9'))
        {
            flag = 1;
            cur++;
            a[cur] = s[i]-'0';
        }
    }
    sort(a+1,a+cur+1,cmp);
    for (int i=1;i<=cur;i++)
    {
        cout<<a[i];
    }
    return 0;
}
