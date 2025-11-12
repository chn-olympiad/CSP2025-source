#include<bits/stdc++.h>
using namespace std;
int a[500050];
int sum[500050];
queue<int> q, p;
long long ans = 0;
int n, k;
int main(){
	freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
	cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(k == 1){
        for(int i = 1; i <= n; i++){
            if(a[i] == 1) ans++;
        }
        cout << ans;
    }else if(k == 0){
        for(int i = 1; i <= n; i++){
            if(a[i] == 0) ans++;
            if(a[i] == a[i - 1] && a[i] == 1){
                ans++;
                a[i - 1] = a[i] = 0;
            }
        }
        cout << ans;
    }else{
        for(int i = 1; i <= n; i++){
            sum[i] = sum[i - 1] ^ a[i];
        }
        q.push(0);
        bool u = false;
        for(int i = 1; i <= n; i++){
            u = false;
            while(q.size()){
                if(((sum[i]) ^ (q.front())) == k){
                    ans++;
                    while(q.size()) q.pop();
                    while(p.size()) p.pop();
                   q.push(sum[i]);
                   u = 1;
                   break;
                }else{
                    p.push(q.front());
                    q.pop();
                }
            }
            if(!u){
                p.push(sum[i]);
                while(p.size()) q.push(p.front()), p.pop();
            }
        }
        cout << ans;
    }
    return 0;
}
