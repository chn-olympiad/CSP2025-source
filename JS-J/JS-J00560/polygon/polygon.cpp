#include<bits/stdc++.h>
using namespace std;
int f(int n){
    int r =1;
    for (int i = 1;i <= n;i++){
        r *= i;
    }
    return r;
}

int f2(int m,int n){
    return (f(m)/(f(n) * f(m - n)));
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    int a[5010];
    for (int i = 0;i < n;i ++){
        cin >> a[i];
    }
    sort (a,a + n);
    int oo;
    if (a[n - 1] == 1){
        for (int i = 3;i <= n;i++){oo += f2(n,i);}
        cout << oo;
    }else{
    int m = 3;
    int b[5010];
    int s, p = 0,h;
    bool f;

    while(m <= n){
        b[0] = 0;
        for (int i = 1;i < m;i ++){b[i] = b[i-1] + 1;}
        f = 0;
        while (true){
            s = 0;
            for (int i = 0;i < m;i++){s += a[b[i]];}
            if (a[b[m - 1]] * 2 < s){
                p ++;
            }
            h = 0;
            while(true){

                if(b[m - h - 1] + 1 < n && b[m - h- 1] + 1 < n - h){

                    b[m- h - 1] ++;
                    for(int i = m - h;i < m;i++){
                            b[i] = b[i-1] + 1;
                    }
                    break;
                }else if(m == h + 1){
                    f = 1;
                    break;
                }else h++;
            }
            if (f == 1)break;
        }
        m ++;
    }
    cout << p;
    }
    return 0;
}
