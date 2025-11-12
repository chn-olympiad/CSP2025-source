#include <iostream>

using namespace std;

typedef unsigned int uint;

bool Select[5555];
uint gunmuLen[5555];

uint gunmuNums = 0;

uint FanganNums = 0;

const uint MOD = 998244353;

void dfs(uint depth){
    if(depth != gunmuNums){
        Select[depth] = false;
        dfs(depth+1);
        Select[depth] = true;
        dfs(depth+1);
    }else{
        // cout << "Depth of ding: " << depth << endl;
        // dao ding le aaaaaaaaaaaa
        uint gunmuLenSum = 0, gunmuLenMax = 0;
        // cout << "Selected: ";
        for(uint i = 0; i < gunmuNums; i++){
            if(Select[i]){
                uint len = gunmuLen[i];
                // cout << len << ' ';
                gunmuLenSum += len;
                if(len > gunmuLenMax) gunmuLenMax = len;
            }
        }
        // cout << ", gunmuLenSum=" << gunmuLenSum << ", gunmuLenMax=" << gunmuLenMax << endl;
        // Fangan Tiaojian: sum{gunmuLen[&Select]} > 2*max{gunmuLen[&Select]}
        if(gunmuLenSum > 2 * gunmuLenMax){
            FanganNums++;
            if(FanganNums==MOD)FanganNums=0;
        }
    }
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> gunmuNums;

    for(uint i = 0; i < gunmuNums; i++){
        cin >> gunmuLen[i];
    }
    
    dfs(0);

    cout << FanganNums;

    return 0;
}