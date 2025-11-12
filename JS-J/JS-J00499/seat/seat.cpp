#include<cstdio>
#include<iostream>
using namespace std;

int n,m,r,g=0;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        int s;
        cin >> s;
        if(i == 1) r=s;
        if(s > r) g++;
    }
    int c = (g)/n+1,R=g%n+1;
    cout << c << " ";
    if(c&1){
        cout << R;
    }else{
        cout << n-R+1;
    }
    return 0;
}
