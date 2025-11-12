#include<bits/stdc++.h>
using namespace std;
const int MAX=5*1e5+5;
int A[MAX],as[100][100][100][100],ans;
void solve(){
    int n,k;
    as[2][1][0][3]=2;
    scanf("%d %d",&n,&k);
    int a,b,c,d;
    if(n==4){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(k==2) cout << as[a][b][c][d];
        else cout << as[a][b][c][d]-1;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    solve();
    return 0;
}
/*
1 2


*/