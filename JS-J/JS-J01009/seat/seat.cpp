#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005],b[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n*m; i++) cin >> b[i];
    int cnt = b[1];
    sort(b+1,b+m*n+1);
    for(int i = 1; i <= n*m; i++){
        a[i] = b[n*m-i+1];
    }
    /*for(int i = 1; i <= n*m; i++){
        cout << a[i] << " ";
    }*/
    if(n % 2){
        for(int i = m; i >= 1; i--){
            if(i%2){
              for(int j = n; j >= 1; j--){
                 if(a[(i-1)*n + j] == cnt){
                       cout << i << " " << j << "\n";
                   }
                }
            }else{
                for(int j = 1; j <= n; j++){
                    if(a[(i-1)*n + (n-j+1)] == cnt){
                        cout << i << " " << j << "\n";
                        //cout << (i-1)*n + (n-j+1) << "\n";
                    }
                }
            }
        }
    }else{
        for(int i = m; i >= 1; i--){
            if(!(i%2)){
                for(int j = n; j >= 1; j--){
                    if(a[(i-1)*n + (n-j+1)] == cnt){
                        cout << i << " " << j << "\n";
                    }
                }
            }else{
                for(int j = 1; j <= n; j++){
                    if(a[(i-1)*n +j] == cnt){
                        cout << i << " " << j << "\n";
                        //cout << (i-1)*n+j << "\n";
                    }   
                }
            }
        }
    }
    return 0;
}
/*
n % 2 && m % 2
input:
3 3
3 95 96 97 1 2 94 4 5
output:
3 1

n % 2 && !(m % 2)
input:
3 2
2 1 5 3 4 6
output:
2 2

!(n % 2) && m % 2
input:
2 3
3 1 2 4 5 6
output:
2 1

!(n % 2) && !(m % 2)
input:
4 4
6 1 2 3 4 5 7 8 9 10 11 12 13 14 15 16
output
3 3
*/