#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int rf,m,n,rzw;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    if(n==1&&m==1){cout<<"1"<<" "<<"1";return 0;}
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    rf=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==rf){
            rzw=i;
            break;
        }
    }
    if(rzw<=n){cout<<"1"<<" "<<rzw;return 0;}
    if(rzw>n&&rzw<=2*n){cout<<"2"<<" "<<n-(rzw-n)+1;return 0;}
    if(rzw>2*n&&rzw<=3*n){cout<<"3"<<" "<<rzw-2*n;return 0;}
    if(rzw>3*n&&rzw<=4*n){cout<<"4"<<" "<<n-(rzw-3*n)+1;return 0;}
    if(rzw>4*n&&rzw<=5*n){cout<<"5"<<" "<<rzw-4*n;return 0;}
    if(rzw>5*n&&rzw<=6*n){cout<<"6"<<" "<<n-(rzw-5*n)+1;return 0;}
    if(rzw>6*n&&rzw<=7*n){cout<<"7"<<" "<<rzw-6*n;return 0;}
    if(rzw>7*n&&rzw<=8*n){cout<<"8"<<" "<<n-(rzw-7*n)+1;return 0;}
    if(rzw>8*n&&rzw<=9*n){cout<<"9"<<" "<<rzw-8*n;return 0;}
    if(rzw>9*n&&rzw<=10*n){cout<<"10"<<" "<<n-(rzw-9*n)+1;return 0;}
    return 0;
}
