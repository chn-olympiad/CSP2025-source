#include <bits/stdc++.h>
using namespace std;
long long n, a[5005], cnt;
int main(){
    freopen("polygen1.in", "r", stdin);
    freopen("polygen.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)cin >> a[i];
    for (int m = 3;m <= n;m++){
        set<int> st;
        for (int i = 1;i <= n;i++)
        {
            for (int j = i;j <= n;j++){
                if (st.find(j) == st.end()){
                    st.insert(j);
                    cnt++;
                }
                else{
                    i++, j++;
                }
            }
        }
    }
    cout << cnt;
}
