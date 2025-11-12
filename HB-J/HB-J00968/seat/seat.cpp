#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int p[m*n];
    int R,P;
    cin >> R;
    p[0] = R;
    for(int i = 1;i < n*m;i++){
        cin >> p[i];
    }
    sort(p,p+m*n);
    for(int i = 0,j = m*n;i < m*n;i++){
        if(R == p[i]){
            P = j;
        }
        j--;
    }
    int L = P / n;
    if((P % n) != 0)L++;
    if(L % 2 == 1){
        cout << L << " "<< P % n;
    }else{
        cout << L << " "<< n - (P % n) + 1;
    }
    return 0;
}
