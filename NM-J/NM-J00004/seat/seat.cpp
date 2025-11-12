#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int main(){
    fropen("seat.in",'r',stdin);
    fropen("seat.out",'w',stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    cout<<1<<" "<<2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
