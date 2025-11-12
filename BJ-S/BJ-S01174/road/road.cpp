

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int _from;
    int _to;
    long long _val;
};

int _maxiV = 0;
int _maxiE = 0;
int _extra = 0;
int _cost[19];
int _costEdge[19][10009];
vector<Edge> _graph[10009];
Edge _myEdge[1000009];
long long _res = 0;

void ParseIn () {
    Edge curEdge;

    ifstream inFile("road.in");

    inFile >> _maxiV >> _maxiE >> _extra;

    for (int i = 0; i < _maxiE; i++) {
        inFile >> curEdge._from >> curEdge._to >> curEdge._val;
        _graph[curEdge._from].push_back(curEdge);
        _myEdge[i] = curEdge;
        swap(curEdge._from, curEdge._to);
        _graph[curEdge._from].push_back(curEdge);
    }

    for (int i = 0; i < _extra; i++) {
        inFile >> _cost[i];

        for (int m = 1; m < _maxiV + 1; m++) {
            inFile >> _costEdge[i][m];
        }
    }

    inFile.close();
}

int _boss[10009];

bool CompareEdge (Edge one, Edge two) {
    return one._val < two._val;
}

int FindBoss (int curV) {
    if (curV == _boss[curV]) {
        return curV;
    }
    _boss[curV] = FindBoss(_boss[curV]);
    return _boss[curV];
}

void Kruskal () {
    sort(_myEdge, _myEdge + _maxiE, CompareEdge);

    for (int i = 1; i < _maxiV; i++) {
        _boss[i] = i;
    }

    for (int i = 0; i < _maxiE; i++) {
        if (FindBoss(_myEdge[i]._from) == FindBoss(_myEdge[i]._to)) {
            continue;
        }
        _res += _myEdge[i]._val;
    }
}

long long _dis[100009];
bool _vis[100009];
long long Prim (int cc) {
    fill(_dis, _dis + cc + 1, 1e18);
    fill(_vis, _vis + cc + 1, false);
    _dis[1] = 0;
    long long res = 0;
    long long minDis = 0;
    int mini = 0;
    for (int i = 0; i < cc; i++) {
        minDis = 1e18;
        mini = 0;
        for (int m = 1; m < cc + 1; m++) {
            if (_dis[m] < minDis && !_vis[m]) {
                mini = m;
                minDis = _dis[m];
            }
        }
        res += minDis;
        //cout << mini << "->" << minDis << ",";
        _vis[mini] = true;
        for (auto to : _graph[mini]) {
            _dis[to._to] = min(_dis[to._to], to._val);
        }
    }
//cout << endl;
    return res;
}

void Core () {
    if (_extra == 0) {
        Kruskal();
        return;
    }

    Edge curEdge;
    _res = 0x7fffffff;
    long long curRes = 0;
    int cc = _maxiV + 1;
    for (int i = 0; i < (1 << _extra); i++) {
        curRes = 0;
        cc = _maxiV;
        //cout << i << "->" << endl;
        for (int m = 0; m < _extra; m++) {
            if ((i >> m) == 1) {
                curRes += _cost[m];
                cc++;
                for (int k = 1; k < _maxiV + 1; k++) {
                    curEdge._from = cc;
                    curEdge._to = k;
                    curEdge._val = _costEdge[m][k];
                    _graph[curEdge._from].push_back(curEdge);
                    swap(curEdge._from, curEdge._to);
                    _graph[curEdge._from].push_back(curEdge);
                }
            }
        }

        curRes += Prim(cc);
       // cout << i << "->" << curRes << endl;
        _res = min(_res, curRes);
        cc = _maxiV + 1;

        for (int m = 0; m < _extra; m++) {
            if ((i >> m) == 1) {
                _graph[cc].clear();
                for (int k = 1; k < _maxiV + 1; k++) {
                    _graph[k].pop_back();
                }
                cc++;
            }
        }

    }
}

void CWriteOut () {
    cout << _res << endl;
}

void WriteOut () {
    ofstream outFile("road.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {

    ParseIn();
    Core();
    WriteOut();

    return 0;
}
