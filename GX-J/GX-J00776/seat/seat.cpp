#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int main(){
    freopen("seat.in","r" ,stdin);
    freopen("seat.out","w" ,stdout);
    int n, m, cl, sc[109] = {0};
    cin>>n>>m;
    cl=n*m;
    for(int i = 0; i < cl; i++){
        cin>>sc[i];
    }
    int r = sc[0], s = 0;
    bool flag = true;
    sort(sc,sc+cl,cmp);
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(sc[s] == r){
                if(flag) cout << i <<" "<< j;
                else cout << i <<" "<< n - j + 1;
                return 0;
            }
            s++;
        }
        flag = !flag;
    }
    return 0;
}
