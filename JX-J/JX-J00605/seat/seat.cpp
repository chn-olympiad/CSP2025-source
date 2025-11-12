#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m;
int num=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]){
            num++;
        }
    }
    int x,y;
    if(num==1){
        cout<<"1 1";
        return 0;
    }
    if(num%n==0){
        x=num/n;
        if(x%2==0) cout<<x<<" "<<1;
        else cout<<x<<" "<<n;
    }
    else{
        x=num/n;
        if(x%2==0){
            y=num%n;
            cout<<x+1<<" "<<y;
        }
        else{
            y=n-(num%n);
            cout<<x+1<<" "<<y+1;
        }
    }
    return 0;
}

