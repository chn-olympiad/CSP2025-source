#include <bits/stdc++.h>
using namespace std;


struct se{
    int sc;
    int tr;

};
bool cmp(int c,int b){
    return c > b;
}
int n,m;
int st[120] = {0};
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n * m;i++){
        cin >> st[i];
    }
    int cnn = st[0];
    int cnt = 0;
    sort(st,st + n * m,cmp);
    for(int i = 0;i <= m;i++){
        if(i % 2 != 1){
            for(int j = 0;j <= n;j++){
                if(st[cnt] == cnn){
                    cout<<min(n,i + 1)<<" "<<min(n,j + 1);
                    return 0;
                }
                cnt++;
            }
        }else{
            for(int j = n;j >= 0;j--){
                if(st[cnt] == cnn){
                    cout<<min(n,i + 1)<<" "<<min(n,j + 1);
                    return 0;
                    }
                }
                cnt++;
            }
        }
    return 0;
}
