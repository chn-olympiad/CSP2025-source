#include <bits/stdc++.h>
using namespace std;

int sc[105];
int n,m,k;
int g;

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >>n >>m;
    for(int i=0;i<n*m;i++){
        cin >>sc[i];
    }
    g=sc[0];
    sort(sc,sc+n*m,cmp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(g==sc[k]){
                if(i%2==1) cout <<i <<" " <<j;
                else cout <<i <<" " <<m-j+1;
                exit(0);
            }
            k++;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
