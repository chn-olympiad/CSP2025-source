//T1
#include <bits/stdc++.h>
using namespace std;


// '0' -> 48
// '9' -> 57

bool cmp(int &a , int &b)
{
    int *ja = &a;
    int *jb = &b;
    return *ja > (*jb);
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    vector<int> q;
    string word;
    cin >> word;
    int cnt = 0;
    int len_size = word.length();
    //cout << int('0') << endl;
    //cout << int('9') << endl;
    for (int i = 0;i<len_size;i++)
    {
        if ( 48 <= int(word[i]) && int(word[i]) <= 57 )
        {
            int even = int(word[i]) - '0';
            q.push_back(even);
            //cout << word[i] << endl;
        }
    }
    sort(q.begin(),q.end(),cmp);
    for (auto x:q)
    {
        cout << x;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
