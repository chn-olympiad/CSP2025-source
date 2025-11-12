

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream inFile("club.in");
ofstream outFile("club.out");

struct Stu {
    int _love[9];
    int _best = 0;
    int _ciBest = 0;
    int _diff = 0;
    Stu () {
        fill(_love, _love + 9, 0);
    }
    void FindBest () {
        _best = 0;
        _ciBest = 0;
        _diff = 0;
        for (int i = 1; i < 4; i++) {
            if (_love[i] >= _love[_best]) {
                _ciBest = _best;
                _best = i;
                continue;
            }
            if (_love[i] >= _love[_ciBest]) {
                _ciBest = i;
            }
        }
        _diff = _love[_best] - _love[_ciBest];
    }
};

int _maxi = 0;
vector<Stu> _club[9];
Stu _myStu[100009];
int _res = 0;

bool CompareStu (Stu one, Stu two) {
    return one._diff > two._diff;
}

void Solve () {
    _club[1].clear();
    _club[2].clear();
    _club[3].clear();

    inFile >> _maxi;
    _res = 0;
    for (int i = 1; i < _maxi + 1; i++) {
        for (int m = 1; m < 4; m++) {
            inFile >> _myStu[i]._love[m];
        }
        _myStu[i].FindBest();
        _club[_myStu[i]._best].push_back(_myStu[i]);
        _res += _myStu[i]._love[_myStu[i]._best];
    }
    int cc = 0;
    //cout << _res << endl;
    for (int i = 1; i < 4; i++) {
        if (_club[i].size() <= _maxi / 2) {
            continue;
        }
        sort(_club[i].begin(), _club[i].end(), CompareStu);
        while (_club[i].size() > _maxi / 2) {
            _res -= _club[i].back()._diff;
            _club[i].pop_back();
        }
    }

    outFile << _res << "\n";
}

int main () {

    int maxi = 0;

    inFile >> maxi;

    for (int i = 0; i < maxi; i++) {
        Solve();
    }

    return 0;
}
