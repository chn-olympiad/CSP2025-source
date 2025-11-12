#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    int len;
    vector <int> t;
    cin >> s;
    len = s.size();
    for(int i = 0; i < len; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            t.push_back(s[i] - '0');
        }
    }
    sort(t.begin(), t.end());
    for(int i = t.size() - 1; i >= 0; i--)
    {
        cout << t[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
