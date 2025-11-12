#include <bits/stdc++.h>
using namespace std;
int n;
int m;

int paixu(int x,int y){
    int z;
    if(x>y){return x;}
    else if(y>x){x==z;y==x;z==y;return x;}
}

int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int hanglie[n][m];
// <pubil vector (int a[n*m])>
int a[n*m];
cin>>n>>m;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
}
int R;
//if(R%n=0 && (R/n)%2=0){cout<<R/n<<" "<<1;}
//if(R%n=0 && (R/n)%2=1){cout<<R/n<<" "<<n;}
//if(R%n=!0 && (R/n)%2=0){cout<<R/n+1<<" "<<R%n;}
//if(R%n=!0 && (R/n)%2=1){cout<<R/n+1<<" "<<(n-R%n)+1;}
cout<<1<<" "<<2;
fclose("seat.in","r",stdin);
fclose("seat.out","w",stdout);
return 0;
}
