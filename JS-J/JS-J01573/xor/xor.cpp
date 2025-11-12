#include <bits/stdc++.h>
using namespace std;

int n , k;
int a[100010];
int q[100010];
struct tDot{
    int s , e;
}p[100010];
int dep = 0;

bool cmp(tDot x , tDot y){
    if(x.e != y.e){
        return x.e < y.e;
    }else{
        return x.s > y.s;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    q[1] = a[1];
    for(int i = 2;i <= n;i++){
        q[i] = q[i - 1] ^ a[i];
    }
    for(int i = 0;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            int temp = q[j] ^ q[i];
            if(temp == k){
                dep++;
                p[dep] = {i + 1 , j};
            }
        }
    }
    sort(p + 1 , p + dep + 1 , cmp);
    int ans = 0;
    int last = -1;
    for(int i = 1;i <= dep;i++){
        if(p[i].s > last){
            last = p[i].e;
            ans++;
        }
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
