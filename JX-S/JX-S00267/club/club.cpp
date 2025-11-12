#include<bits/stdc++.h>
using namespace std;
int T;
int n , s = 0;
int main(){
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    cin>> T;
    while(T--){
        cin>> n;
        vector<int> a(n + 1) , b(n + 1) , c(n + 1);
        int a1 = 0 , b1 = 0 , c1 = 0;
        bool tmp1 = true , tmp2 = true;
        for(int i = 1; i <= n; i++){
            cin>> a[i] >> b[i] >> c[i];
            if(b[i] != 0 || c[i] != 0) tmp1 = false;
            if(c[i] != 0) tmp2 = false;
        }
        if(tmp1) cout<< n / 3 << endl;
        else if(tmp2){
            for(int i = 1; i <= n; i++){
                int x = max(a[i] , b[i]);
                if(x == a[i] && a1 < n / 3){
                    s += x;
                    a1++;
                }
                else if(x == a[i] && a1 >= n / 3){
                    if(b1 < n / 3){
                        s += b[i];
                        b1++;
                    }
                    else if(b1 >= n / 3){
                        c1++;
                        }
                }
                else if(x == b[i] && b1 < n / 3){
                    s += x;
                    b1++;
                }
                else if(x == b[i] && b1 >= n / 3){
                    if(a1 < n / 3){
                        s += a[i];
                        a1++;
                    }
                    else if(a1 >= n / 3){
                        c1++;
                    }
                }
            }
            cout<< s << endl;
        }
        else{
            for(int i = 1; i <= n; i++){
                int x = max(max(a[i] , b[i]) , c[i]);
                if(x == a[i] && a1 < n / 3){
                    s += x;
                    a1++;
                }
                else if(x == a[i] && a1 >= n / 3){
                    int y = max(b[i] , c[i]);
                    if(y == b[i] && b1 < n / 3){
                        s += y;
                        b1++;
                    }
                    else if(y == b[i] && b1 >= n / 3){
                        s += c[i];
                        c1++;
                    }
                    else if(y == c[i] && c1 < n / 3){
                        s += y;
                        c1++;
                    }
                    else{
                        s += b[i];
                        b1++;
                    }
                }
                else if(x == b[i] && b1 < n / 3){
                    s += x;
                    b1++;
                }
                else if(x == b[i] && b1 >= n / 3){
                    int y = max(a[i] , c[i]);
                    if(y == a[i] && a1 < n / 3){
                        s += y;
                        a1++;
                    }
                    else if(y == a[i] && a1 >= n / 3){
                        s += c[i];
                        c1++;
                    }
                    else if(y == c[i] && c1 < n / 3){
                        s += y;
                        c1++;
                    }
                    else{
                        s += a[i];
                        a1++;
                    }
                }
                else if(x == c[i] && c1 < n / 3){
                    s += c[i];
                    c1++;
                }
                else{
                    int y = max(a[i] , b[i]);
                    if(y == a[i] && a1 < n / 3){
                        s += y;
                        a1++;
                    }
                    else if(y == a[i] && a1 >= n / 3){
                        s += b[i];
                        b1++;
                    }
                    else if(y == b[i] && b1 < n / 3){
                        s += y;
                        b1++;
                    }
                    else{
                        s += a[i];
                        a1++;
                    }
                }
            }
            cout << s << endl;
        }
        s = 0 , a1 = 0 , b1 = 0 , c1 = 0;
    }
    return 0;
}
