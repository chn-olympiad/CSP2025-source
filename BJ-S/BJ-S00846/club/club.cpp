#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
long long n, m, r1, r2, r3, c[N], d[N], y, z, l, w, sum;
struct s{
    long long a1, a2, a3;
}a[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> n;

    for(int i = 0; i < n; i++){

        sum = 0;
        cin >> m;
        for(int j = 1; j <= m; j++){
            r1 = m/2;
            r2 = r1;
            r3 = r2;
            y = 0, z= 0;
            cin >> a[j].a1 >> a[j].a2 >> a[j].a3;
            y = max(y, max(max(a[j].a1,a[j].a2),a[j].a3));
            z = min(y, min(min(a[j].a1,a[j].a2),a[j].a3));
          //  a[j+m] = a[j];
          //  a[j+m+m] = a[j];
            c[j] = y-z;
            d[j] = c[j];
          //  cout << c[j] << " ";
        }
        sort (c+1, c+m+1);
        for(int j = m; j >= 1; j--){
      //     cout << c[j] << "/";
            for(int k = 1; k <= m; k++){
         //       cout << d[k] << " ";
                if(d[k] == c[j]){
  //                  cout << ")";
                    if((a[k].a2>a[k].a1) && (a[k].a2>a[k].a3) && (r2>0)) {sum += a[k].a2, r2--;}
                    else if((a[k].a3>a[k].a1) && (a[k].a3>a[k].a2) && (r3>0)) {sum += a[k].a3, r3--;}
                    else{
                        sum += a[k].a1, r1--;
                    }
                    a[k].a1 = 0, a[k].a2 = 0, a[k].a3 = 0, d[k] = 0;
                    if(r1 == 0){
                        for(int kk = 1; kk <+ m; kk++) a[kk].a1 = 0;
                    }
                    if(r2 == 0){
                        for(int kk = 1; kk <+ m; kk++) a[kk].a2 = 0;
                    }
                    if(r3 == 0){
                        for(int kk = 1; kk <+ m; kk++) a[kk].a3 = 0;
                    }
                    break;
                }
            }
            //cout << sum << "  ";
        }

        //cout << endl;
        for(int j = 1; j <= m; j++){
            a[j].a1 = 0;
            a[j].a2 = 0;
            a[j].a3 = 0;
        }
        cout << sum;
        if(i != n-1) cout << endl;
    }

    return 0;
}
