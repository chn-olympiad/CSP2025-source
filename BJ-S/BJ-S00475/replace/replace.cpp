#include <iostream>
#include <map>
using namespace std;

struct Node
{
    string od;
    string nw;
} a[10005];

Node check(string s1, string s2)
{
    int n = s1.size();
    s1 = " " + s1;
    s2 = " " + s2;
    int l = 1, r = n;
    if (s1 == s2)
    {
        return {"", ""};
    }
    for (int i = 1; i <= n; i++)
    {
        if (s1[i] == s2[i])
        {
            l++;
        }
        else
        {
            break;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (s1[i] == s2[i])
        {
            r--;
        }
        else
        {
            break;
        }
    }
    Node ans;
    string temp = "";
    for (int i = l; i <= r; i++)
    {
        temp += s1[i];
    }
    ans.od = temp;
    temp = "";
    for (int i = l; i <= r; i++)
    {
        temp += s2[i];
    }
    ans.nw = temp;
    return ans;
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n;
    cin >> q;
    for (int i = 1; i <= n; i++)
    {
        string temp1;
        cin >> temp1;
        string temp2;
        cin >> temp2;
        Node temp = check(temp1, temp2);
        a[i] = temp;
    }
    while (q--)
    {
        string temp1;
        string temp2;
        cin >> temp1;
        cin >> temp2;
        Node temp = check(temp1, temp2);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i].od == temp.od && a[i].nw == temp.nw)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
