#include <bits/stdc++.h>
using namespace std;
int h[105];
int s[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,j,hang,lie,num;
    int r;
    hang=lie=1;
    num=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>h[i];
        j=h[i];
        s[j]++;
    }
    r=h[1];
    for(int i=r;i<=100;i++){
         if(s[i]==1){
            num++;
         }
    }
    if(num>n){
        lie=num/n;
        if(lie%n>0){
            lie++;
        }
        if(num%n==0){
        if(lie%2==0){
            hang=1;
        }
        else if(lie%2==1){
            hang=n;
        }
    }
    else if(num%n>0){
        if(lie%2==0){
            hang=n-num%n;
        }
        else{
            hang=num%n;
        }
    }
    }
    else if(num<=n){
        hang=num;
    }
    cout<<lie<<" "<<hang;
    return 0;
}
