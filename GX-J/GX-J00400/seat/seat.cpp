#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n][m];
    int b[n*m],mx;
    for(int i=1;i<=m*n;i++){
        cin>>b[i];
    }
    mx=b[1];
    int v=0;
    for(int i=1;i<=m*n;i++){
        if(mx<b[i]){
            v++;
        }
    }
    int i=0,j=0;
    bool top=false;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
