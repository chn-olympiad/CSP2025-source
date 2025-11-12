#include <bits/stdc++.h>
using namespace std;
int mod = 998244353, n[5008], ant, ans, ma;
int f(int a, int b){
    return a > b;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.in","w",stdout);
	int a;
	cin >> a;
    for(int i = 0; i < a; i++){
        cin >> n[i];
    }
    sort(n, n + a, f);
    for(int i = 0; i < a; i++){
        for(int j = i; j < a; j++){
                ma += n[j];
                ant++;
            if(ant >= 3 && n[j] * 2 < ma){
                ans++;
            }
        }
        ma = 0;
    }
    cout << ans;
	return 0;
}
