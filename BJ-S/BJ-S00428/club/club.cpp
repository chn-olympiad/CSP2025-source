#include <bits/stdc++.h>
using namespace std;

int one[100005];

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int group;
    int newer;
    int f,e;
    int total = 0;
    cin >> group;
    while(group > 0){
        total = 0;
        cin >> newer;
        for(int i = 1; i <= newer*3; i++){
            cin >> one[i] >> f >> e;
        }
        sort(one + 1, one + newer + 1);
        for(int i = 0; i < newer/2; i++){
            total = one[newer - i] + total;
        }        
        cout << total;
        group++;
    }
    return 0;
}