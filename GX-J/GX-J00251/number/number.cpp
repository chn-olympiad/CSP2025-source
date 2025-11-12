#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    vector<int>a;
    string s;
    cin >> s;
    int len=s.size();
    for (int i=0; i<len; i++) if (s[i] >= '0' && s[i] <= '9') a.push_back(s[i]-'0');
    for (int i=0; i<(a.end()-a.begin()); i++)
    {
        int max=0;
        for (int j=0; j<(a.end()-a.begin()); j++)
        {
            if (a[j] > a[max])
            {
                max=j;
            }

        }
        cout << a[max];
        a[max]=-1;
    }
    return 0;
}
