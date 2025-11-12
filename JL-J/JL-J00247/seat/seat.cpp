#include<bits/stdc++.h>
using namespace std;
int s[10][10];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>s[i][j];
            if(s[1][1]<s[i][j]){
                a++;
            }
        }
    }
    if(a/n==0){
        cout<<1;
    }else if((a%n)!=0 &&(a/n)<n){
    cout<<(a/n)+1;
    }else {
    cout<<a/n;
    }
    if((a%n)==0){
        cout<<" "<<n;
    }else{
        cout<<" "<<a%n;
    }


    return 0;
}
