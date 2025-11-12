#include<bits/stdc++.h>
using namespace std;
int n,m,f,tx,a1,ty;
int a[101];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    f=n*m;
    for(int i=1;i<=f;i++){
        cin>>a[i];
    }
    a1=a[1];
    sort(a+1,a+f+1,cmp);
    for(int i=1;i<=f;i++){
        if(a[i]==a1){
            a1=i;
            break;
        }
    }
        if(a1%n==0){

            ty=a1/n;
            if(ty%2==0){
                tx=1;
            }
            else{
                tx=n;
            }
        }
        else{
            ty=a1/n+1;
            if(ty%2==0){
                tx=n-a1%n+1;
            }
            else{
                tx=a1%n;
            }
        }


    cout<<ty<<" "<<tx;
    return 0;
}
