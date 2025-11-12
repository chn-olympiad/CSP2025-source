#include <bits/stdc++.h>
using namespace std;

int n;
struct node
{
    int num,les;
};

bool cmp(node a,node b){return a.les < b.les;}
int main()
{
    freopen ("club.in","r",stdin);
    freopen ("club.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector <node> stua,stub,stuc;
        for (int i = 1;i <= n;i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            if (a >= b and a >= c) stua.push_back({a,a - max(b,c)});
            else if (b >= c and b > a) stub.push_back({b,b - max(a,c)});
            else stuc.push_back({c,c - max(a,b)});
        }
        int sum = 0;
        for (auto curr : stua) sum += curr.num;
        for (auto curr : stub) sum += curr.num;
        for (auto curr : stuc) sum += curr.num;
        if (stua.size() > n / 2)
        {
            sort (stua.begin(),stua.end(),cmp);
            for (int i = 0;i < stua.size() - n / 2;i++) sum -= stua[i].les;
        }
        if (stub.size() > n / 2)
        {
            sort (stub.begin(),stub.end(),cmp);
            for (int i = 0;i < stub.size() - n / 2;i++) sum -= stub[i].les;
        }
        if (stuc.size() > n / 2)
        {
            sort (stuc.begin(),stuc.end(),cmp);
            for (int i = 0;i < stuc.size() - n / 2;i++) sum -= stuc[i].les;
        }
        cout << sum << "\n";
    }
    fclose (stdin);
    fclose (stdout);
    return 0;
}