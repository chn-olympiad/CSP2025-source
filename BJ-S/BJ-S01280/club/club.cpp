#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void sortA(auto arr, int leng){
    for (int i = 1;i<leng;i++){
        int j = i;
        while (j != 0 && arr[j][0] > arr[j-1][0]){
            j--;
        }
        int cur = arr[j][0];
        arr[j][0] = arr[i][0];
        arr[i][0] = cur;
    }
}
auto choose(auto group, vector<int> joined, int n){
    int score = 0;
    size_t original = joined.size()
    for (int i = 0;i<n;i++){
        if (joined.size() - original == n/2){
            break;
        }
        if (count(begin(joined), end(joined), group[i][1]) == 0){
            joined.push_back(group[i][1])
            score += group[i][0]
        }
    }
    return joined, score;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0;i<t;i++){
        int n;
        cin >> n;
        int g1[n][2], g2[n][2], g3[n][2];
        for (int j = 0;j<n;j++){
            cin >> g1[j][0] >> g2[j][0] >> g3[j][0];
            g1[j][1] = j; g2[j][1] = j; g3[j][1] = j;
        }
        sortA(g1, n); sortA(g2, n); sortA(g3, n);


    }
    return 0;
}
