#include<bits/stdc++.h>
using namespace std;

int ma(int x,int y,int z){
    int c[2];
    c[0] = x;
    c[1] = y;
    c[2] = z;
    if (x>=z&&x>=y){
        return x-x;
    }
    if (z>=x&&z>=y){
        return x-x+1;
    }
    if (y>=z&&y>=x){
        return x-x+2;
    }
}
int er(int x,int y,int z){
    int c[2];
    c[0] = x;
    c[1] = y;
    c[2] = z;
    if ((x<=z)&&(x>=y) or (x>=z)&&(x<=y)){
        return x-x;
    }
    if ((z>=x)&&(z<=y) or (z>=x)&&(z<=y)){
        return x-x+1;
    }
    if ((y>=z)&&(y<=x) or (y>=x)&&(y<=z)){
        return x-x+2;
    }
}
int mi(int x,int y,int z){
    int c[2];
    c[0] = x;
    c[1] = y;
    c[2] = z;
    if (x<=z&&x<=y){
        return x-x;
    }
    if (z<=x&&z<=y){
        return x-x+1;
    }
    if (y<=z&&y<=x){
        return x-x+2;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    int a[1000][1000];
    int b[10] = {0};
    int d[10] = {0};
    cin >> t;

    for(int j=1;j<=t;j++){
        cin >> n;

        for(int i=1;i<=n;i++){
            cin >>a[i][0]>>a[i][1]>>a[i][2];



        cout << a[i][0]+a[i][1]+a[i][2];

    }}


    fclose(stdin);
    fclose(stdout);

    return 0;
}
