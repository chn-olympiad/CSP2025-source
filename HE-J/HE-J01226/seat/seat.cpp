#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[20][20],b[20][20],m,n,num=1;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]>a[0][0]) num++;
        }
    }
    int c=num/n;
    if(c%2==1) {
        if (num%n==0){
            cout<<c<<" "<<n;
        }
        else{
            cout<<c<<" "<<num%n;

        }
    }
    else {
    if (num%n==0){
            cout<<c<<" "<<1;
        }
        else{
            cout<<c<<" "<<n-num%n+1;
        }
    }




    fclose(stdin);
    fclose(stdout);
    return 0;
}
