#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    cin >> n;
    int len = 0;
    for(int i = 0; i <= n.size(); i++)
        if(n[i] >= '0' && n[i] <= '9')
        {
            len++;
            a[len] = int(n[i] - '0');
        }
    sort(a + 1, a + len + 1);
    for(int i = len; i >= 1; i--) cout << a[i];
    return 0;
}
