#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int c[a*b];
    for(int i=0;i<a*b;i++){
        cin>>c[i];
    }
    int d=c[0],e;
    for(int i=0;i<a*b-1;i++){
        for(int j=0;j<a*b-1;j++){
            if(c[j]<c[j+1]){
                e=c[j+1];
                c[j+1]=c[j];
                c[j]=e;
            }
        }
    }
    for(int i=0;i<b;i++){
        for(int j=0;j<a;j++){
            if(c[i*a+j]==d&&i%2==0){
                cout<<i+1<<' '<<j+1;
            }else if(c[i*a+j]==d&&i%2!=0){
                cout<<i+1<<' '<<b-j;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
