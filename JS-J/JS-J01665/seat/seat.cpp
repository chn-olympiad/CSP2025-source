#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m,s=1;
    cin>>n>>m;
    int b;
    cin>>b;
    for(int i=2;i<=n*m;i++){
        int a;
        cin>>a;
        if(a>b){
            s++;
        }
    }
    int x,y;
    if(s%n==0){
        x=s/n;
    }
    else {
        x=s/n+1;
    }
    y=s%n;
    if(y==0){
        y=n;
    }
    if(x%2==1){
        cout<<x<<" "<<y;
    }
    else{
        cout<<x<<" "<<n+1-y;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
