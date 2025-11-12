#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 10;

string s1[N];
string s2[N];

bool check(string x,string y,string a,string b)
{
    for(int i = 0; i < x.size(); i++)
    {
        if(i + a.size() - 1 >= x.size()) continue;
        string t = "";
        bool flag = true;
        for(int j = 0; j < x.size(); j++)
        {
            if(j < i) t += x[j];
            else if(j > i + a.size() - 1) t += x[j];
            else
            {
                if(x[j] == a[j - i]) t += b[j - i];
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag == false) continue;
        if(t == y) return true;
    }
    return false;
}

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> s1[i];
        cin >> s2[i];
    }
    while(q--)
    {
        string x,y;
        cin >> x >> y;
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            if(check(x,y,s1[i],s2[i])) cnt++;
        cout << cnt << "\n";
    }
    return 0;
}
