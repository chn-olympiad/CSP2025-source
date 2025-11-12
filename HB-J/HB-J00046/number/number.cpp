#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string sum = "";
    string s;
    cin >> s;
    vector<char> data;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] < 'a' || s[i] > 'z')
        {
            data.push_back((s[i]));
        }
    }
    sort(data.begin(),data.end(),greater<int>());
    for(int i = 0;i < data.size();i++)
    {
        sum += data[i];
    }
    cout << sum;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
