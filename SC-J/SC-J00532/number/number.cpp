#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+2;
char nums[maxn];
int num[10] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> nums;
    for(int i=0; i<sizeof(nums); i++){
        if(nums[i] <= '9' && nums[i] >= '0'){
            num[nums[i]-48] ++;
        }
    }

    for(int i=9; i>=0; i--){
        while(num[i] > 0){
            cout << i;
            num[i] --;
        }
    }

    return 0;
}