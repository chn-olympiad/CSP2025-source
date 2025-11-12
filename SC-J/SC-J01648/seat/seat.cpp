#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n*m];
    for(int i=0;i<n*m;i++){
        cin >> a[i];
    }
    int K=a[0];
    sort(a,a+n*m);
    int R=1;
    while(a[n*m-R]!=K){
        R++;
    }
    int Rm=(R%n==1)?(R/n+1):(R/n);
    int Rn;
    if(Rm%2!=0){//ji
        Rn=R-Rm*n+n;
    }
    else{//ou
        Rn=Rm*n-R+1;
    }
    cout << Rm << " " << Rn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
