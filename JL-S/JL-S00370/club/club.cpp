#include<iostream>
using namespace std;
int a[10001] = {},b[101] = {};
int t,n;
void pd(){
    int zd = 0,l = 0;
    for(int i = 0;i < 3;i++){
        if(a[i] > zd){
            if(b[i]+1 <= n/2){
                zd = a[i];
                l = i;
            }else{
                a[i] = 0;
                pd();
            }
        }
    }
}
int main(){ 
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i < 3;i++){
            b[i] = 0;
        }
        for(int i = 0;i < n;i++{
            for(int j = 0;j < 3;j++){
                cin >> a[j];
            }
            pd();
            b[l] += a[l];
        }
        int c = 0;
        for(int i = 0;i < 3;i++){
            c += b[i];
        }
        cout << c << endl;
    }
    return 0;
}

