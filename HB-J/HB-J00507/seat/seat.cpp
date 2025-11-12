#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
int a[maxn];

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int shu = n*m;
    int sum = 0;
    cin >> a[1];
    for(int i = 2;i <= shu;i++){
        cin >> a[i];
        if(a[i] > a[1]){
            sum++;
        }
    }
    cout << sum/n+1 << " ";
    if(((sum/n)%2+1)%2 == 1){
        cout << sum-((sum/n)*n)+1;
    }else if(((sum/n)%2+1)%2 == 0){
        cout << n-(sum-((sum/n)*n));
    }
    return 0;
}
