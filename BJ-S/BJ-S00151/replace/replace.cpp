#include <bits/stdc++.h>
using namespace std;

struct mv
{
    int length;
    int go;
}p[200000];

mv l[200000];
string key = "b";

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n,q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        string a,b;
        cin >> a >> b;
        p[i].length = a.length();
        int posa = a.find("b");
        int posb = b.find("b");
        p[i].go = posb-posa;
    }
    for(int i = 0; i < q; i++)
    {
        string a,b;
        cin >> a >> b;
        l[i].length = a.length();
        int posa = a.find("b");
        int posb = b.find("b");
        l[i].go = posb-posa;
    }
    for(int i = 0; i < q; i++)
    {
        int ans = 0;
        for(int j = 0; j < n; j++)
        {
            if(p[j].length > l[i].length)
                continue;
            if(p[j].go == l[j].go)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
