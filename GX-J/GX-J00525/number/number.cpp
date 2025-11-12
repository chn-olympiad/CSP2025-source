#include "bits/stdc++.h"

using namespace std;

int main(){
//     freopen("number.in", "r", stdin);
//     freopen("number.out", "w", stdout);

    string l;
    cin >> l;

    vector<int> useNum;

    int i=0;
    while (i<l.size()){
        string l;
        l = cin.get();
        cout << i << ":" << l << endl;
        if (l == "1"){
            useNum.push_back(1);
        }
        else if (l == "2"){
            useNum.push_back(2);
        }
        else if (l == "3"){
            useNum.push_back(3);
        }
        else if (l == "4"){
            useNum.push_back(4);
        }
        else if (l == "5"){
            useNum.push_back(5);
        }
        else if (l == "6"){
            useNum.push_back(6);
        }
        else if (l == "7"){
            useNum.push_back(7);
        }
        else if (l == "8"){
            useNum.push_back(8);
        }
        else if (l == "9"){
            useNum.push_back(9);
        }
        else if (l == "0"){
            useNum.push_back(0);
        }

        i++;
    }
    cout << useNum.size() << endl;
    for (int i=0; i<useNum.size(); i++){
        cout << useNum[i];
    }
    
    return 0;
}
