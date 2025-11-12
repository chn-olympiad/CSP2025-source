#include<bits/stdc++.h>
using namespace std;
int n,m,a[130],t[15][15],x=1,y=1,k=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int flag;
    flag=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(a[i]==flag){
            cout<<y<<" "<<x<<endl;
            break;
        }
        if(k/n==0){
            x++;
        }else if(k%n==0){
            y++;
        }else if(k/n==1){
            x--;
        }
        if(k/n==2){
            k=1;
        }else{
            k++;
        }

    }

    return 0;
}
