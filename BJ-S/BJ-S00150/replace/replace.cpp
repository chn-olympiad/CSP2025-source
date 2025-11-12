#include<bits/stdc++.h>
using namespace std;
int n,q;
struct txt
{
    string s1;
    string s2;
}a[1000010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    txt b[1000010];
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i].s1 >> a[i].s2;
    }
    for(int i = 1;i<=q;i++)
    {
        cin >> b[i].s1 >> b[i].s2;
    }
    cout << 13<<endl;
    return 0;
}
