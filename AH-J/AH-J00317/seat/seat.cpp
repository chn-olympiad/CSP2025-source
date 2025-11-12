#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101],a2[101],b[11][11];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++){
        cin >> a[i];
        a2[i] = a[i];
    }
    sort(a2+1,a2+n*m,cmp);
    int temp = 1;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            b[i][j] = a2[temp];
            temp++;
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(b[i][j] == a[1]){
                cout << i << " " << j;
            }
        }
    }
    return 0;
}
