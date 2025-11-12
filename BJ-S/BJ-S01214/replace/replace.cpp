#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int n, m;
string cp[10009][2], qst[2];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> cp[i][0] >> cp[i][1];
    }
    for(int i = 0; i < m; i++){
        cin >> qst[0] >> qst[1];
        int ans = 0;
        for(int j = 0; j < n; j++){
            if(qst[0].find(cp[i][0])){
                string s = qst[0];
                s.replace(qst[0].find(cp[i][0]), qst[0].find(cp[i][0]) + cp[i][0].size(), cp[i][1]);
                if(s == qst[1]){
                    ans++;
                }
            }
        }
        cout <<ans <<endl;
    }
    return 0;
}
