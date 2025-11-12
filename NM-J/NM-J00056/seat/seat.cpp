#include<bits/stdc++.h>
using namespace std;

int a[110][110];
int s[10010];
int m ,n;
int ans;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin >> m >> n;
    for(int i = 1;i <= m * n;i++){
        cin >> s[i];
        ans = s[1];
    }
    sort(s + 1,s + n * m + 1,greater<int>());

    int cnt;
    for(int i = 1;i <= m * n;i++){
        if(s[i] == ans) cnt = i;
    }

    int c;
    if(cnt % n == 0){
        c = cnt / n;
    }else{
        c = cnt / n + 1;
    }
    int sum = cnt % n;
    int r;
    if(sum != 0){
        if(c % 2 == 0){
            r = n - sum + 1;
        }else{
            r = sum;
        }
    }else{
        if(c % 2 == 0){
            r = 1;
        }else{
            r = n;
        }
    }
    cout << c << " " << r << endl;

    return 0;

}
