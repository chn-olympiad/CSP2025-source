#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<string*> rps;
    for (int i = 0;i<n;i++){
        string s[2];
        cin >> s[0] >> s[1];
        rps.push_back(s);
    }
    vector<string*> qts;
    for (int i = 0;i<q;i++){
        string s[2];
        cin >> s[0] >> s[1];
        qts.push_back(s);
    }
    return 0;
}

