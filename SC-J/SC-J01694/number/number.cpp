#include <bits/stdc++.h>
using namespace std;

bool cmp(char a, char b) {
    if(a < b)
        return false;
    return true;
}

int main() {
    string s, n;
    ifstream fin;
    ofstream fout;
    fin.open("./number.in");
    fout.open("./number.out");
    //cin >> s;
    fin >> s;
    for(char c : s) {
        if('0' <= c && c <= '9') {
            n += c;
        }
    }
    sort(n.begin(), n.end(), cmp);
    fout << n;
    fin.close();
    fout.close();
    return 0;
}
