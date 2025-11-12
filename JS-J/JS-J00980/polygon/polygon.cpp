#include <bits/stdc++.h>
using namespace std;
long long jc(int a,int n){
    long long s = 0;
    for (int i = 1;i <= n;i++){
        s = s * i;
    }
    return s;
}

long long A(int a,int b,int n){
    if (a == b){
        return jc(a,n);
    }
    else{
        return jc(b,n) / jc(a,n);
    }
}
long long C(int a,int b,int n){
    return A(a,b,n) / A(a,a,n);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,fs = 0;
    vector<int> v;
    vector<int> f;
    vector<int> maxx;
    cin >> n;
    bool ff = true;
    for (int i = 0;i < n;i++){
        int tf;
        cin >> tf;
        if (i == 0){
            f.push_back(tf);
            maxx.push_back(tf);
        }
        else{
            f.push_back(f[i - 1] + tf);
            maxx.push_back(max(maxx[i - 1],tf));
        }
        if (tf != 1){
            ff = false;
        }
        v.push_back(tf);
    }
    if (n < 3){
        cout << (0 % 998244353);
    }
    else if (ff){
        int t = 0;
        for (int i = 3;i <= n;i++){
            t += C(i,n,n);
        }
        cout << (t % 998244353);
    }
    else{
        for (int i = 0;i < f.size();i++){
            for (int j = i + 2;j < f.size();j++){
                int t=-1;
                if (maxx[i] == maxx[j]){
                    for (int k = i;k < j;k++){
                        t= max(t,v[i]);
                    }
                    if (f[j] - f[i] > t * 2) fs++;
                }
                else if (f[j] - f[i] > 2 * maxx[j]){
                    fs++;
                }
                cout << i << ' '<< j << endl;
            }
        }
        cout << (fs % 998244353);
    }
    return 0;
}
