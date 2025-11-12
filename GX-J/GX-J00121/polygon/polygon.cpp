#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int m ,Max=0 ,s=0 ,zo ,n;
    cin >> m;
    int a[m] ,fz=1 ,fm=1 ,be=123 ,d;
    for(int i=1 ; i<=m ; i++){
        cin >> a[i];
        if(a[i]>Max){
            Max=a[i];
        }
    }
    for(int i=3 ; i<=m ; i++){
        for(int j=m ; j>m-i; j--){
            fz=fz*j;
        }
        for(int l=i ; l>=2 ; l--){
            fm=fm*l;
        }
        zo = fz / fm;
        fz=1;
        fm=1;
    }
    while(zo){
        while(be){
            d=be%10;
            cout << d << endl;
            be=be/10;
            s = s + a[d];
            cout << s << endl;
            if(2*Max<s){
                zo--;
                n++;
            }
        }
        be++;
    }
    cout << n;

    return 0;
}
