#include <bits/stdc++.h>
using namespace std;

int s[105];
int x,t;

bool cmp(int x,int y){
    return x > y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin >> n >> m;
    int sum = n * m;
    for(int i = 1;i <= sum;i++){
        cin >> s[i];
    }
    x = s[1];
    sort(s + 1,s + sum + 1,cmp);
    for(int i = 1;i <= sum;i++){
        if(s[i] == x){
            t = i;
            break;
        }
    }
    int c = 0,r = 0;
    if(t % n == 0){
        c = t / n;
    }
    else{
        c = t / n + 1;
    }
    cout << c << ' ';
    t -= (c - 1) * n;
    if(c & 1){
        r = t;
    }
    else{
        r = n - t + 1;
    }
    cout << r;
    return 0;
}
