#include <bits/stdc++.h>
using namespace std;
int a[110];
int c[110];

bool cmp(int x,int y){
    return x > y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    bool flag = true;
    for(int i = 1;i <= n * m;i++){
        cin >> a[i];
        c[i] = a[i];
        if(a[i] != i) flag = false;
    }if(flag == true){
        cout << n << ' ' << m;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }flag = true;
    sort(c + 1,c + n * m + 1,cmp);
    for(int i = 1;i <= n;i++){
        if(c[i] != a[i]){
            flag = false;
            break;
        }
    }if(flag == true){
        cout << 1 << ' ' << 1;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }flag = true;
    sort(c + 1,c + n * m + 1);
    for(int i = 1;i <= n;i++){
        if(c[i] != a[i]){
            flag = false;
            break;
        }
    }if(flag == true){
        cout << n << ' ' << m;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    int xr = a[1];
    sort(a + 1,a + n * m + 1,cmp);
    for(int i = 1;i <= n * m;i++){
        if(a[i] == xr){
            int lieshu;
            if(i % n == 0) lieshu = i / n;
            else lieshu = i / n + 1;
            if(lieshu % 2 == 0){
                cout << lieshu << ' ' << n - (i % n) + 1;
            }else{
                cout << lieshu << ' ' << i - (lieshu - 1) * n;
            }
        }
    }fclose(stdin);
    fclose(stdout);
    return 0;
}
