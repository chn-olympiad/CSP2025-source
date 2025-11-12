#include<iostream>
#include<algorithm>
using namespace std;

int num[105];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int N = 0, M = 0, r = 0;
    cin >> N >> M;
    for(int i = 0;i < N * M;i ++){
        cin >> num[i];
    }
    r = num[0];
    sort(num, num + N * M, cmp);
    for(int n = 0;n < N;n ++){
        for(int m = 0;m < M;m ++){
            if(m % 2 == 0){
                if(num[N * m + n] == r){
                    cout << m + 1 << ' ' << n + 1 << "\n";
                    return 0;
                }
            }
            else {
                if(num[N * m + N - n - 1] == r){
                    cout << m + 1 << ' ' << n + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}
