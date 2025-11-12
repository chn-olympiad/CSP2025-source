#include <iostream>
#include <vector>
#include <algorithm>

int n, m;

int arr[300];

int seat[20][20];

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for(int i=1;i<=n*m;i++) std::cin >> arr[i];
    int score=arr[1];
    std::sort(arr+1, arr+n*m+1, std::greater<int>());
    for(int i=1, p=1;i<=m;i++) { // i: lie, j: hang
        if(i&1) {
            for(int j=1;j<=n;j++) seat[i][j]=arr[p++];
        }
        else {
            for(int j=n;j>=1;j--) seat[i][j]=arr[p++];
        }
    }
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            if(seat[i][j]==score) {
                std::cout << i << ' ' << j << '\n';
            }
        }
    }
}
