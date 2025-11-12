#include <bits/stdc++.h>
using namespace std;

int n;
int a[5001];
long long ans;
int stk[5001];
int top;

int get_max(){
    int tmp = 0;
    for (int i = 0; i < top;i++){
        tmp = max(tmp, stk[i]);
    }
    return tmp;
}

bool judge(){
    int tmp1 = 0;
    int tmp2 = 0;
    for (int i = 0; i < top; i++)
    {
        tmp1 = max(tmp1, stk[i]);
        tmp2 += stk[i];
        if(i<n-1 and stk[i]>stk[i+1])
            return 0;
    }
    return tmp2 > 2 * tmp1;
}

void fun(int dep){
    if(dep>n){
        return;
    }
    if(top >= 3 and judge())
    {
        ans++;
        ans %= 998244353;
    }
    for (int i = 0; i <= n;i++){
            if(a[i]!=-1){
                stk[top++] = a[i];
                a[i] = -1;
                fun(dep + 1);
                a[i] = stk[--top];
            }
    }
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    fun(0);
    cout << ans << endl;
    return 0;
}