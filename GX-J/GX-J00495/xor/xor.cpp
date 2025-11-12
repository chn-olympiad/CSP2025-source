#include<bits/stdc++.h>
using namespace std;
int n, k, res;
int a[500001];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == k)
            res++;
    }
    for(int i = 1; i <= n; i++){
        int ans = i + 1;
        int sum = i;
        while(ans <= n){
            sum = i;
            for(int j = i + 1; j <= ans; j++){
                sum |= a[j];
            }
            if(sum == k)
                res++;
            ans++;
        }
    }
    cout << res;
	return 0;
}
