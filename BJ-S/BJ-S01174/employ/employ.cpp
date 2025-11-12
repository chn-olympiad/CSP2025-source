

#include <iostream>
#include <fstream>

using namespace std;

int _maxi = 0;
int _least = 0;
string _test = "";
int _pat[19];
int _seq[19];
bool _vis[19];
int _res = 0;

void DFS (int cc) {

    int cnt = 0;
    int res = 0;
    if (cc == _maxi) {
        for (int i = 0; i < cc; i++) {
            //cout << _seq[i] << ",";
            if (_pat[_seq[i]] <= cnt) {
                cnt++;
                continue;
            }
            if (_test[i] == '0') {
                cnt++;
                continue;
            }
            res++;
        }
        //cout << "->" << res << endl;
        if (res >= _least) {
            _res++;
        }
        return;
    }

    for (int i = 0; i < _maxi; i++) {
        if (!_vis[i]) {
            _seq[cc] = i;
            _vis[i] = true;
            DFS(cc + 1);
            _seq[cc] = 0;
            _vis[i] = false;
        }
    }
}

void ParseIn () {
    ifstream inFile("employ.in");

    inFile >> _maxi >> _least;

    inFile >> _test;

    for (int i = 0; i < _maxi; i++) {
        inFile >> _pat[i];
    }

    inFile.close();
}

void Core () {
    DFS(0);
}

void CWriteOut () {
    cout << _res << endl;
}

void WriteOut () {
    ofstream outFile("employ.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {

    ParseIn();
    Core();
    WriteOut();

    return 0;
}
