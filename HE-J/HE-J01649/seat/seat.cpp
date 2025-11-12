#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N],res,u,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int t=n*m;
    for(int i=1;i<=t;i++){
        cin>>a[i];
    }
    u=a[1];
    sort(a+1,a+1+t);
    for(int i=t;i>=1;i--){
        if(a[i]==u) res=t-i+1;
    }
    if(res%n==0){
        x=res/n;
        if(x%2!=0){
            y=n;
            cout<<x<<" "<<y<<endl;
        }else{
            y=1;
            cout<<x<<" "<<y<<endl;
        }
    }else{
        x=res/n+1;
        if(x%2!=0){
            y=res%n;
            cout<<x<<" "<<y<<endl;
        }else{
            y=n-(res%n)+1;
            cout<<x<<" "<<y<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
