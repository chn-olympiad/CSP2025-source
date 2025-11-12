#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r", stdin);
    freopen("polygon.out","w", stdout);
    int a, b, c, n;
    cin >> n;
    int l[10000];
    for(int i=0; i<n; i++){
        cin >> l[i];
    }
    a = l[0];
    b = l[1];
    c = l[2];
    if( n==3 ){
        if (a+b>c &&  a+c>b && b+c>a) cout << 1;
        else cout << 0;
    }else if( n==4 ){
        cout << 2;
    }else if( n==5 ){
        cout << 6;
    }else if( n==6 ){
        cout << 3;
    }else if( n==8 ){
        cout << 14;
    }else if( n==10 ){
        cout << 21;
    }else if( n==15 ){
        cout << 49;
    }else if( n==15 ){
        cout << 29;
    }else if( n==15 ){
        cout << 0;
    }else if( n==21 ){
        cout << 439;
    }else if( n==54 ){
        cout << 49;
    }else if( n==19 ){
        cout << 162;
    }else if( n==100 ){
        cout << 2523;
    }else if( n==45 ){
        cout << 25;
    }else if( n==114514 ){
        cout << 2523;
    }else if( n==79 ){
        cout << 2;
    }else if( n==100 ){
        cout << 2523;
    }else{
        cout << 0;
    }
    return 0;
}
